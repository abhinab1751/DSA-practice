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
-------------------------------------------------------------------------------------------------------------------->
    #include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;
        
        for (int l = 0; l < layers; ++l) {
            int top = l;
            int bottom = m - 1 - l;
            int left = l;
            int right = n - 1 - l;
            
            vector<int> vals;
            
            for (int j = left; j <= right; ++j) {
                vals.push_back(grid[top][j]);
            }
            for (int i = top + 1; i <= bottom; ++i) {
                vals.push_back(grid[i][right]);
            }
            for (int j = right - 1; j >= left; --j) {
                vals.push_back(grid[bottom][j]);
            }
            for (int i = bottom - 1; i > top; --i) {
                vals.push_back(grid[i][left]);
            }

            int rot = k % vals.size();

            rotate(vals.begin(), vals.begin() + rot, vals.end());
            
            int idx = 0;
            for (int j = left; j <= right; ++j) {
                grid[top][j] = vals[idx++];
            }
            for (int i = top + 1; i <= bottom; ++i) {
                grid[i][right] = vals[idx++];
            }
            for (int j = right - 1; j >= left; --j) {
                grid[bottom][j] = vals[idx++];
            }
            for (int i = bottom - 1; i > top; --i) {
                grid[i][left] = vals[idx++];
            }
        }
        
        return grid;
    }
};
----------------------------------------------------------------------------------------------------------------->
    class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (dp[j] != -1 &&
                    abs((long long)nums[i] - nums[j]) <= target) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
