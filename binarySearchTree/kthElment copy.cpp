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
    int prevOrder = 0;

    int kthSmallest(TreeNode* root , int k){
        if(root == NULL){
            return -1;
        }

        if(root -> left != NULL){
            int leftAns = kthSmallest(root->left , k);
            if(leftAns != -1){
                return leftAns;
            }
        }

        if(prevOrder + 1 == k){
            return root -> val;
        }
        prevOrder = prevOrder + 1;

        if(root -> right != NULL){
           int rightAns = kthSmallest(root -> right, k);
           if(rightAns != -1){
            return rightAns;
           }
        }
        return -1;
    }
};

int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    int ans = obj.kthSmallest(root, k);

    if(ans != -1)
        cout << k << "th smallest element is: " << ans << endl;
    else
        cout << "Invalid k!" << endl;

    return 0;
}

