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

Node* insert(Node* root , int val){
    if(root == NULL) {
        return new Node(val);
    }

    if(val < root -> data){
        root -> left = insert(root->left, val);
    }
    else{
        root -> right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }

        if(root->data == key){
            return true;
        }                                        //  SEARCH
        if(root->data > key){
            return search(root->left, key);
        }
        else{
            return search(root->right, key);
        }
    }

Node* getInorderSuccessor(Node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key < root->data) {
        root->left = delNode(root->left, key);
    } else if(key > root->data){
        root->right = delNode(root->right, key);
    } else {
        if(root -> left == NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        } else {
            Node* IS = getInorderSuccessor(root -> right);
            root -> data = IS->data;
            root->right = delNode(root -> right, IS -> data);
        }
    }
    return root;
}


Node* buildBST(vector<int> arr){
    Node* root = NULL;

    for(int val: arr){
        root = insert(root , val);
    }

    return root;
}


int main(){

    vector<int> arr = {5, 3, 7, 1, 4, 6, 8};

    Node* root = buildBST(arr);

    //cout << "Inorder Traversal of BST: ";
    //inorder(root);

    cout << search(root, 9)<< endl;

    return 0;
}


class Fancy {
    static const int MOD = 1e9 + 7;
    vector<long long> seq;
    long long mul = 1, add = 0;

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

public:
    Fancy() {}

    void append(int val) {
        long long inv_mul = power(mul, MOD - 2, MOD);
        seq.push_back((val - add % MOD + MOD) % MOD * inv_mul % MOD);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= (int)seq.size()) return -1;
        return (seq[idx] * mul % MOD + add) % MOD;
    }
};

//-------------------------------------------------->
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> maxDP(m, vector<long long>(n));
        vector<vector<long long>> minDP(m, vector<long long>(n));

        maxDP[0][0] = minDP[0][0] = grid[0][0];

       
        for(int i = 1; i < m; i++) {
            maxDP[i][0] = minDP[i][0] = maxDP[i-1][0] * grid[i][0];
        }

       
        for(int j = 1; j < n; j++) {
            maxDP[0][j] = minDP[0][j] = maxDP[0][j-1] * grid[0][j];
        }

        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                long long val = grid[i][j];

                long long a = maxDP[i-1][j] * val;
                long long b = minDP[i-1][j] * val;
                long long c = maxDP[i][j-1] * val;
                long long d = minDP[i][j-1] * val;

                maxDP[i][j] = max({a, b, c, d});
                minDP[i][j] = min({a, b, c, d});
            }
        }

        long long ans = maxDP[m-1][n-1];
        if(ans < 0) return -1;
        return ans % MOD;
    }
};
