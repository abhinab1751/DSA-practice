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

class Info {
    public:
    int min, max, sz;

    Info(int mi, int ma, int size){
        min = mi;
        max = ma;
        sz = size;
    }
};

Info helper(Node* root){
    if(root == NULL){
        return Info(INT16_MAX,INT16_MIN,0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root -> data > left.max && root -> data < right.min){
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currsz = left.sz + right.sz + 1;

        return Info(currMin, currMax , currsz);
    }

    return Info(INT16_MIN, INT16_MAX, max(left.sz, right.sz));
}

int largestBSTinBT(Node* root){
    Info info = helper(root);
    return info.sz;
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left=new Node(1);
    root->left->right= new Node(8);
    root->right->right= new Node(7);

    cout << largestBSTinBT(root) << endl;
    return 0;
}