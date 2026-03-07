#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int val){
        data = val;
        left=right= NULL;
        next = NULL;

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

class BSTIterator{
    public:
    stack<TreeNode*> s;

    void storeLeftNodes(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root -> left;
        }
    }

    BSTIterator(TreeNode* root){
        storeLeftNodes(root);
    }

    int next() {
        TreeNode* ans = s.top();
        s.pop();

        storeLeftNodes(ans->right);
        return ans->val;
    }

    bool hasNext() {
        return s.size() > 0;
    }
};

int main() {

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);


    BSTIterator it(root);

    while(it.hasNext()){
        cout << it.next() << " ";
    }

    return 0;
}