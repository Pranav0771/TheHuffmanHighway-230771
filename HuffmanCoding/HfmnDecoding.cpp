#include <bits/stdc++.h>
using namespace std;

class HuffmanNode {
public:
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

class Compare {
public:
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->freq > right->freq;
    }
};

class HuffmanCoding {
private:
    HuffmanNode* root;
    unordered_map<char, int> freqMap;

    void buildFrequencyMap(char data, int freq);
    void buildHuffmanTree();

public:
    HuffmanCoding() : root(nullptr) {}
    // ~HuffmanCoding();
    void decompress(const string& inputFileName, const string& outputFileName);
};

void HuffmanCoding::buildFrequencyMap(char data, int freq) {
    freqMap[data] = freq;
}

void HuffmanCoding::buildHuffmanTree() {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    for (auto pair : freqMap) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (minHeap.size() != 1) {
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();

        int sum = left->freq + right->freq;
        HuffmanNode* node = new HuffmanNode('\0', sum);
        node->left = left;
        node->right = right;

        minHeap.push(node);
        // cout << "Priority Queue contents:" << endl;
        // priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> tempHeap = minHeap; 
        // while (!tempHeap.empty()) {
        //     HuffmanNode* node = tempHeap.top();
        //     cout << "Character: " << node->data << ", Frequency: " << node->freq << endl;
        //     tempHeap.pop();
        // }
    }

    root = minHeap.top();
}

// HuffmanCoding::~HuffmanCoding() {
//     function<void(HuffmanNode*)> deleteTree = [&](HuffmanNode* node) {
//         if (!node) return;
//         deleteTree(node->left);
//         deleteTree(node->right);
//         delete node;
//     };
//     deleteTree(root);
// }

void HuffmanCoding::decompress(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName, ios::in);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return;
    }
    buildFrequencyMap('k', 2); buildFrequencyMap('j', 1); buildFrequencyMap('p', 8);
    buildFrequencyMap('x', 1) ;buildFrequencyMap('K', 1); buildFrequencyMap('.', 3);
    buildFrequencyMap('h', 7); buildFrequencyMap('c', 4); buildFrequencyMap('e', 17);
    buildFrequencyMap('d', 7); buildFrequencyMap('y', 2); buildFrequencyMap('C', 1);
    buildFrequencyMap('o', 16); buildFrequencyMap('n', 8); buildFrequencyMap('a', 6);
    buildFrequencyMap('w', 1);buildFrequencyMap(' ', 29);buildFrequencyMap('g', 6);
    buildFrequencyMap('t', 14);buildFrequencyMap('r', 7);buildFrequencyMap('u', 6);
    buildFrequencyMap('l', 4);buildFrequencyMap('i', 5);buildFrequencyMap('s', 5);
    buildFrequencyMap('I', 1);buildFrequencyMap('f', 2);buildFrequencyMap(',', 1);

    buildHuffmanTree();
    
    string encodedString((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    ofstream outputFile(outputFileName, ios::out);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    string decodedString;
    HuffmanNode* currentNode = root;
    for (char bit : encodedString) {
        // cout << bit << endl;
        if (bit == '0') {
            currentNode = currentNode->left;
        }
        else if (bit == '1') {
            currentNode = currentNode->right;
        }

        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            decodedString += currentNode->data;
            currentNode = root;
        }
    }

    outputFile << decodedString;
    outputFile.close();
}

int main() {
    HuffmanCoding huffman;
    string inputFileName = "compressed.txt";
    string outputFileName = "decoded.txt";

    huffman.decompress(inputFileName, outputFileName);
    cout << "Decompression complete." << endl;

    return 0;
}