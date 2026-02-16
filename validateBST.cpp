#include <iostream>
#include <vector>
#include <algorithm>
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

bool helper(TreeNode* root , TreeNode* min , TreeNode* max){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root->val <= min->val){
        return false;
    }
    if(max != NULL && root->val >= max -> val){
        return false;
    }

    return helper(root->left, min , root) &&
           helper(root->right, root , max);
}

bool isValidBST(TreeNode* root){
    return helper(root, NULL, NULL);
}

int main() {

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(8);

    if(isValidBST(root)){
        cout << "Valid BST";
    } else {
        cout << "Not a BST";
    }

    return 0;
}
