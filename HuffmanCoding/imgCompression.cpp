#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

// Define a struct for Huffman tree nodes
struct Node {
    int frequency;
    unsigned char symbol;
    Node* left;
    Node* right;

    Node(int freq, unsigned char symb) : frequency(freq), symbol(symb), left(nullptr), right(nullptr) {}
};

// Compare nodes for priority queue
struct compareNodes {
    bool operator()(Node* l, Node* r) {
        return l->frequency > r->frequency;
    }
};

// Generate Huffman codes
void generateCodes(Node* root, map<unsigned char, string>& codes, string currentCode) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        codes[root->symbol] = currentCode;
    }

    generateCodes(root->left, codes, currentCode + "0");
    generateCodes(root->right, codes, currentCode + "1");
}

// Compress image using Huffman coding
void compressImage(const vector<unsigned char>& image, const map<unsigned char, string>& codes, ofstream& compressedFile) {
    unsigned char buffer = 0; 
    int bitCount = 0; 

    for (unsigned char pixel : image) {
        string code = codes.at(pixel);
        for (char bit : code) {
            buffer = (buffer << 1) | (bit == '1');
            bitCount++;

            if (bitCount == 8) {
                compressedFile.write(reinterpret_cast<const char*>(&buffer), 1);
                buffer = 0; 
                bitCount = 0;
            }
        }
    }

    if (bitCount > 0) { 
        buffer = buffer << (8 - bitCount); 
        compressedFile.write(reinterpret_cast<const char*>(&buffer), 1);
    }
}

// Load image using stb_image
vector<unsigned char> loadImage(const string& filename) {
    int width, height, channels;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &channels, STBI_grey);

    if (data == nullptr) {
        cerr << "Error: Could not load image " << filename << endl;
        exit(1);
    }

    vector<unsigned char> image(data, data + width * height * channels);
    stbi_image_free(data);
    return image;
}

// Clean up the Huffman tree
void cleanUp(Node* root) {
    if (root == nullptr) return;
    cleanUp(root->left);
    cleanUp(root->right);
    delete root;
}

int main() {
    // Load the image (assuming grayscale for simplicity)
    vector<unsigned char> image = loadImage("image1.png");

    map<unsigned char, int> frequency;
    for (unsigned char pixel : image) {
        frequency[pixel]++;
    }

    priority_queue<Node*, vector<Node*>, compareNodes> pq;
    for (const auto& pair : frequency) {
        pq.push(new Node(pair.second, pair.first));
    }

    Node* root = nullptr;
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node(left->frequency + right->frequency, '$');
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }
    root = pq.top();

    map<unsigned char, string> codes;
    generateCodes(root, codes, "");

    ofstream compressedFile("compressed.bin", ios::binary);
    if (!compressedFile) {
        cerr << "Error: Cannot open the output file!" << endl;
        return 1;
    }
    compressImage(image, codes, compressedFile);
    compressedFile.close();

    cleanUp(root);

    return 0;
}

