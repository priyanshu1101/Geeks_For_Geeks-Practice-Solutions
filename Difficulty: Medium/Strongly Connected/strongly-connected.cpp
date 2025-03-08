//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution {
  public:
    void topoSort(vector<vector<int>> &adj,stack<int> &stk,int curr,vector<bool> &visited){
        visited[curr]=true;
        for(int adjNode:adj[curr]){
            if(!visited[adjNode]){
                topoSort(adj,stk,adjNode,visited);
            }
        }
        stk.push(curr);
    }
    void dfs(vector<vector<int>> &adj,int curr,vector<bool> &visited){
        visited[curr]=true;
        for(int adjNode:adj[curr]){
            if(!visited[adjNode]){
                dfs(adj,adjNode,visited);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // topo sort
        stack<int> stk;
        vector<bool> visited(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                topoSort(adj,stk,i,visited);
            }
        }
        // reverse the graph
        vector<vector<int>> rev(adj.size(),vector<int>(0));
        for(int i=0;i<adj.size();i++){
            for(int adjNode:adj[i]){
                rev[adjNode].push_back(i);
            }
        }
        // dfs
        int ans=0;
        fill(visited.begin(),visited.end(),false);
        while(!stk.empty()){
            int top = stk.top();
            stk.pop();
            if(!visited[top]){
                ans++;
                dfs(rev,top,visited);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends