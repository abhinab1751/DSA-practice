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



class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e16, ans = right;

        auto can = [&](long long t){
            long long total = 0;

            for(long long w : workerTimes){
                long long x = (-1 + sqrt(1 + 8.0 * t / w)) / 2;
                total += x;
                if(total >= mountainHeight) return true;
            }

            return total >= mountainHeight;
        };

        while(left <= right){
            long long mid = left + (right - left) / 2;

            if(can(mid)){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<string> res;

    void backtrack(string curr, int n){
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }

        for(char ch : {'a','b','c'}){
            if(curr.empty() || curr.back() != ch){
                backtrack(curr + ch, n);
            }
        }
    }

    string getHappyString(int n, int k) {
        backtrack("", n);

        if(res.size() < k) return "";
        return res[k-1];
    }
};

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> sums;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                sums.insert(grid[i][j]); 

                for(int k=1;;k++){
                    if(i-k<0 || i+k>=m || j-k<0 || j+k>=n) break;

                    int sum = 0;

                    int x = i-k, y = j;

                    
                    for(int t=0;t<k;t++) sum += grid[x+t][y+t];


                    for(int t=0;t<k;t++) sum += grid[i+t][j+k-t];

                   
                    for(int t=0;t<k;t++) sum += grid[i+k-t][j-t];

                    
                    for(int t=0;t<k;t++) sum += grid[i-t][j-k+t];

                    sums.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto it = sums.rbegin(); it!=sums.rend() && ans.size()<3; it++)
            ans.push_back(*it);

        return ans;
    }
};






----------------------------------------------------------------------------------------------------------------->
    #include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py)
            parent[py] = px;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        for (auto &p : allowedSwaps) {
            dsu.unite(p[0], p[1]);
        }

        
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[dsu.find(i)].push_back(i);
        }

        int res = 0;

       
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    res++;
                }
            }
        }

        return res;
    }
};


---------------------------------------------------------------------------------------------->
    class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for (string &q : queries) {
            for (string &d : dictionary) {
                int diff = 0;

                for (int i = 0; i < q.size(); i++) {
                    if (q[i] != d[i]) {
                        diff++;
                        if (diff > 2) break;
                    }
                }

                if (diff <= 2) {
                    result.push_back(q);
                    break; 
                }
            }
        }

        return result;
    }
};





---------------------------------------------------------------------------------------->
    class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n, 0);
        
        for (auto &it : mp) {
            vector<int> &v = it.second;
            int m = v.size();
            
            vector<long long> prefix(m, 0);
            prefix[0] = v[0];
            
            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + v[i];
            }
            
            for (int i = 0; i < m; i++) {
                long long left = 0, right = 0;
                
                if (i > 0) {
                    left = (long long)v[i] * i - prefix[i - 1];
                }
                
                if (i < m - 1) {
                    right = (prefix[m - 1] - prefix[i]) - (long long)v[i] * (m - i - 1);
                }
                
                ans[v[i]] = left + right;
            }
        }
        
        return ans;
    }
};




---------------------------------------------------------------------------------------------------------------->
    class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blank = 0;
        
        for(char c : moves) {
            if(c == 'L') left++;
            else if(c == 'R') right++;
            else blank++;
        }
        
        return abs(left - right) + blank;
    }
};
----------------------------------------------------------------------->
    #include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long mapTo1D(long long x, long long y, long long side) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 2LL * side + (side - x);
        if (x == 0) return 3LL * side + (side - y);
        return 0; 
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> A;
        A.reserve(n);
        
        for (const auto& p : points) {
            A.push_back(mapTo1D(p[0], p[1], side));
        }
        sort(A.begin(), A.end());

        vector<long long> P(2 * n);
        for (int i = 0; i < n; ++i) {
            P[i] = A[i];
            P[i + n] = A[i] + 4LL * side;
        }

        long long low = 1, high = side;
        long long ans = 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            vector<int> nxt(2 * n, 2 * n);
            int j = 0;
            for (int i = 0; i < 2 * n; ++i) {
                while (j < 2 * n && P[j] - P[i] < mid) {
                    j++;
                }
                nxt[i] = j;
            }

            bool possible = false;
            
            for (int i = 0; i < n; ++i) {
                int curr = i;
                int count = 1;
                
               
                for (int step = 1; step < k; ++step) {
                    curr = nxt[curr];
                    if (curr >= 2 * n) break; // Exceeded boundaries
                    count++;
                }
                
                
                if (count == k && P[curr] - P[i] <= 4LL * side - mid) {
                    possible = true;
                    break;
                }
            }

            
            if (possible) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }

        return static_cast<int>(ans);
    }
};
