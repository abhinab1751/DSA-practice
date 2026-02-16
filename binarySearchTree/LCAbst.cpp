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

class Solution{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p , TreeNode* q){
        if(root == NULL){
            return NULL;
        }

        if(root -> val > p->val && root -> val > q-> val){
            return lowestCommonAncestor(root -> left , p , q);
        }
        else if(root -> val < p->val && root -> val < q->val){
            return lowestCommonAncestor(root->right, p , q);
        }
        else{
            return root;
        }
    }
};


int main() {


    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;              
    TreeNode* q = root->left->right;       

    Solution obj;
    TreeNode* lca = obj.lowestCommonAncestor(root, p, q);

    if(lca != NULL){
        cout << "Lowest Common Ancestor is: " << lca->val << endl;
    }
    else{
        cout << "LCA not found!" << endl;
    }

    return 0;
}

