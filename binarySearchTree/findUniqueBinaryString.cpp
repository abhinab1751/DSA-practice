class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";

        for(int i = 0; i < n; i++){
            if(nums[i][i] == '0')
                ans += '1';
            else
                ans += '0';
        }

        return ans;
    }
};



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<vector<long long>>> dp(
            zero + 1,
            vector<vector<long long>>(one + 1, vector<long long>(2, 0))
        );

        for(int i = 1; i <= min(zero, limit); i++)
            dp[i][0][0] = 1;

        for(int j = 1; j <= min(one, limit); j++)
            dp[0][j][1] = 1;

        for(int i = 1; i <= zero; i++) {
            for(int j = 1; j <= one; j++) {

                dp[i][j][0] =
                    (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;

                if(i - limit - 1 >= 0)
                    dp[i][j][0] =
                        (dp[i][j][0] - dp[i-limit-1][j][1] + MOD) % MOD;

                dp[i][j][1] =
                    (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;

                if(j - limit - 1 >= 0)
                    dp[i][j][1] =
                        (dp[i][j][1] - dp[i][j-limit-1][0] + MOD) % MOD;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};


class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int mask = 0;
        int temp = n;

        while(temp > 0){
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        return mask ^ n;
    }
};