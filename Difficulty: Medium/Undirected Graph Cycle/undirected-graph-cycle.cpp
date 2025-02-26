//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(vector<vector<int>>& adj,int node,vector<bool> &visited){
        queue<pair<int,int>> que;
        que.push({-1,node});
        visited[node]=true;
        while(!que.empty()){
            pair<int,int> top = que.front();
            que.pop();
            int parent = top.first,curr=top.second;
            for(int adjNode : adj[curr]){
                if(!visited[adjNode]){
                    visited[adjNode]=true;
                    que.push({curr,adjNode});
                }
                else if(adjNode!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(),false);
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                bool detectCycle = detect(adj,i,visited);
                if(detectCycle) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends