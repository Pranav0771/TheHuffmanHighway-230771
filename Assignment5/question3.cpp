#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

TreeNode* buildTree(vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nums.size() && nums[i] != -1) {
            curr->left = new TreeNode(nums[i++]);
            q.push(curr->left);
        }
        if (i < nums.size() && nums[i] != -1) {
            curr->right = new TreeNode(nums[i++]);
            q.push(curr->right);
        }
    }
    return root;
}

void evaluate(TreeNode* root, const vector<pair<int, int>>& queries){
    
}

int main(){
    string input;
    cout << "Enter tree nodes in level order (use -1 for NULL): ";
    getline(std::cin, input);
    vector<int> arr;
    int i=0;
    while(input[i] != '/0'){
        arr.push_back(input[i]);
        i++;
    }
    TreeNode* root = buildTree(arr);
    vector<pair<int, int>> queries;
    int n;
    cout << "Enter number of queries: ";
    cin >> n;
    for (int i=0; i<n; i++){
        int first;
        int second;
        cin >> first;
        cin >> second;
        queries.push_back({first, second});
    }
    evaluate(root, queries);
}