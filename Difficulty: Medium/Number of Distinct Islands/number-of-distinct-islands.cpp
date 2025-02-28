//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    void bsf(vector<vector<int>>& grid,int i,int j,vector<pair<int,int>> &shape){
        queue<pair<int,int>> que;
        que.push({i,j});
        int basei = i, basej = j;
        grid[i][j]=0;
        while(!que.empty()){
            pair<int,int> top=que.front();
            que.pop();
            for(auto dir:directions){
                int i=top.first+dir[0],j=top.second+dir[1];
                if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1){
                    grid[i][j]=0;
                    que.push({i,j});
                    shape.push_back({i-basei,j-basej});
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> islands;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>> shape;
                    bsf(grid,i,j,shape);
                    islands.insert(shape);
                }
            }
        }
        return islands.size();
    }
};

// 00 01 10 11  23 24 33 34

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends