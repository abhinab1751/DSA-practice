#include<iostream>
#include<list>
#include<vector>
#include<queue>   
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }
    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printAdjList() {
        for(int i = 0;i<V;i++){
            cout<< i << " : ";
            for(int neigh : l[i]) {
                cout << neigh << " ";
            }
            cout<<endl;
        }
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;

        // push all rotten oranges first
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int i = front.first.first;
            int j = front.first.second;
            int time = front.second;

            ans = max(ans,time);

            if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1){
                q.push({{i-1,j},time+1});
                vis[i-1][j] = true;
            }

            if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == 1){
                q.push({{i,j+1},time+1});
                vis[i][j+1] = true;
            }

            if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 1){
                q.push({{i+1,j},time+1});
                vis[i+1][j] = true;
            }

            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1){
                q.push({{i,j-1},time+1});
                vis[i][j-1] = true;
            }
        }

        
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << "Time required: " << sol.orangesRotting(grid) << endl;

    return 0;
}