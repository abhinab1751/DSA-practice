#include <iostream>
#include <vector>
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

Node* rightMostInLeftSubtree(Node* root) {
    Node* ans;

    while(root != NULL){
        ans = root;
        root = root -> right;
    }
    return ans;
}

Node* leftMostInRightSubtree(Node* root) {
    Node* ans;

    while(root != NULL){
        ans = root;
        root = root -> left;
    }
    return ans;
}

vector<int> getPredSucc(Node* root , int key){
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL) {
        if(key < curr->data){
            succ = curr;
            curr = curr -> left;
        } else if(key > curr -> data){
          pred = curr;
          curr = curr -> right;  
        } else {
            if(curr -> left != NULL){
                pred = rightMostInLeftSubtree(curr->left);
            }
            if(curr -> right != NULL){
                succ = leftMostInRightSubtree(curr -> right);
            }
            break;
        }
    }
    return {pred -> data , succ -> data};
}


int main() {


    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);

    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->right->left = new Node(25);
    root->right->right = new Node(35);

    int key = 20;

    vector<int> ans = getPredSucc(root, key);

    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;

    return 0;
}