#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right; 
    Node(int val) : data(val), left(NULL), right(NULL){}
}Node;

Node* buildTree(Node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);    
    if(data == -1) {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

bool isIsomorphic(Node* root1, Node* root2) {

    if (root1 == nullptr && root2 == nullptr)
        return true;

    if (root1 == nullptr || root2 == nullptr)
        return false;

    
    return (isIsomorphic(root1->left, root2->left) && 
            isIsomorphic(root1->right, root2->right));
}

int main(){
    
    Node* root1 = NULL;
    root1 = buildTree(root1);
    Node* root2 = NULL;
    root2 = buildTree(root2);

    if(isIsomorphic(root1, root2)){
        cout << "The two trees are isomorphic.";
    }
    else{
        cout << "The two trees are not isomorphic.";
    }
}


