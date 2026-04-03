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

//------------------------------------------------------------------

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(i > 0) grid[i][j] += grid[i-1][j];
                if(j > 0) grid[i][j] += grid[i][j-1];
                if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];

                if(grid[i][j] <= k) count++;
            }
        }

        return count;
    }
};



/-------------------------------------------------------

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> temp(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[j][n - i - 1] = mat[i][j];
            }
        }

        mat = temp;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int k = 0; k < 4; k++) {
            if(mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};

//-------------------------------------------------------
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<char> word(n, '\0');
        
        
        int char_idx = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] != '\0') continue;
            if (char_idx >= 26) return "";
            
            word[i] = 'a' + char_idx++;
            
            
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    if (word[j] != '\0' && word[j] != word[i]) return "";
                    word[j] = word[i];
                }
            }
        }
        
        
        vector<vector<int>> actual(n + 1, vector<int>(n + 1, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                actual[i][j] = (word[i] == word[j]) ? actual[i+1][j+1] + 1 : 0;
                if (actual[i][j] != lcp[i][j]) return "";
            }
        }
        
        return string(word.begin(), word.end());
    }
};

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        if (!((s1[0] == s2[0] && s1[2] == s2[2]) ||
              (s1[0] == s2[2] && s1[2] == s2[0])))
            return false;

        
        if (!((s1[1] == s2[1] && s1[3] == s2[3]) ||
              (s1[1] == s2[3] && s1[3] == s2[1])))
            return false;

        return true;
    }
};


//-------------------------------------------------------------------------------------->
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(m, vector<long long>(3, LLONG_MIN))
        );

        
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;  
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (dp[i][j][k] == LLONG_MIN) continue;

                    
                    if (j + 1 < m) {
                        int val = coins[i][j + 1];

                        
                        dp[i][j + 1][k] = max(dp[i][j + 1][k],
                                              dp[i][j][k] + val);

                        
                        if (val < 0 && k < 2) {
                            dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1],
                                                      dp[i][j][k]);
                        }
                    }

                    
                    if (i + 1 < n) {
                        int val = coins[i + 1][j];

                        
                        dp[i + 1][j][k] = max(dp[i + 1][j][k],
                                              dp[i][j][k] + val);

                        
                        if (val < 0 && k < 2) {
                            dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1],
                                                      dp[i][j][k]);
                        }
                    }
                }
            }
        }

        long long ans = max({dp[n-1][m-1][0],
                             dp[n-1][m-1][1],
                             dp[n-1][m-1][2]});

        return (int)ans;
    }
};
