#include <iostream>
#include <vector>
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


class Solution {
    public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;

    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root -> left);

        if(prev != NULL && prev->val > root -> val){
            if(first == NULL){
                first = prev;
            }
            sec = root;
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root){
        inorder(root);

        int temp = first->val;
        first->val = sec -> val;
        sec->val = temp;
    }
    
};

void printInorder(TreeNode* root){
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main(){

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    Solution obj;
    obj.recoverTree(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}

