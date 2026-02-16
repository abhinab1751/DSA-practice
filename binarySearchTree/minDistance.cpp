#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left=right= NULL;

    }
};

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
    TreeNode* prev = NULL;

    int minDiff(TreeNode* root){
        if(root == NULL){
            return INT16_MAX;
        }

        int ans = INT16_MAX;
        if(root -> left != NULL){
            int leftMin = minDiff(root -> left);
            ans = min(ans,leftMin);
        }

        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        if(root -> right != NULL){
            int rightMin = minDiff(root -> right);
            ans = min(ans , rightMin);
        }
        return ans;
    }
};


int main() {

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    int result = obj.minDiff(root);

    cout << "Minimum difference in BST: " << result << endl;

    return 0;
}
