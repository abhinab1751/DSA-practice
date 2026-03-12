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
    int git (int n) {
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


class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    
    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        
        if(rank[a]<rank[b]) swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
        
        return true;
    }
};

class Solution {
public:
    
    bool check(int n, vector<vector<int>>& edges, int k, long long x){
        DSU dsu(n);
        int upgrades=0;
        int used=0;
        
        vector<vector<int>> opt;
        
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];
            
            if(must){
                if(s<x) return false;
                if(dsu.unite(u,v)) used++;
                else return false;
            }else{
                opt.push_back(e);
            }
        }
        
        vector<vector<int>> upg;
        
        for(auto &e:opt){
            int u=e[0],v=e[1],s=e[2];
            
            if(s>=x){
                if(dsu.unite(u,v)) used++;
            }
            else if(2LL*s>=x){
                upg.push_back(e);
            }
        }
        
        for(auto &e:upg){
            if(upgrades==k) break;
            
            int u=e[0],v=e[1];
            if(dsu.unite(u,v)){
                upgrades++;
                used++;
            }
        }
        
        return used==n-1;
    }
    
    
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        long long l=0,r=2e5,ans=-1;
        
        while(l<=r){
            long long mid=(l+r)/2;
            
            if(check(n,edges,k,mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        
        return ans;
    }
};

