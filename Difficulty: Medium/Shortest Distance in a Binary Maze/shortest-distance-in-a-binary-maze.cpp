//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
    bool isDirectionValid(int i,int j,vector<vector<int>> &grid)
    {
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==1;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        map<pair<int,int>,int> distance;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                distance[{i,j}]=INT_MAX;
            }
        }
        queue<vector<int>> que;
        distance[source]=0;
        que.push({source.first,source.second,0});
        while(!que.empty()){
            vector<int> top = que.front();
            que.pop();
            for(vector<int> dir:directions){
                int i = top[0]+dir[0],j=top[1]+dir[1],dist=top[2];
                if(isDirectionValid(i,j,grid) && distance[{i,j}]>dist+1){
                    distance[{i,j}]=dist+1;
                    que.push({i,j,dist+1});
                }
            }
        }
        int ans = distance[{destination.first,destination.second}];
        return ans==INT_MAX? -1:ans;
    }
};



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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends