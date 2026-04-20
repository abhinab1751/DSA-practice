#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        
        vector<int> ans(n, -1);
        
        for (auto& [val, indices] : pos) {
            int k = indices.size();
            if (k > 1) {
                for (int i = 0; i < k; i++) {
                    int curr = indices[i];
                    
                    int prev_idx = indices[(i - 1 + k) % k];
                    int next_idx = indices[(i + 1) % k];
                    
                    int dist_prev = min(abs(curr - prev_idx), n - abs(curr - prev_idx));
                    int dist_next = min(abs(curr - next_idx), n - abs(curr - next_idx));
                    
                    ans[curr] = min(dist_prev, dist_next);
                }
            }
        }
        
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            result[i] = ans[queries[i]];
        }




------------------------------------------------------------------------------------------->
    #include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;
        
        for (int j = n - 1; j >= 0; j--) {
            if (colors[j] != colors[0]) {
                maxDist = j;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                maxDist = max(maxDist, (n - 1 - i));
                break;
            }
        }

        return maxDist;
    }
};
        
        return result;
    }
};
