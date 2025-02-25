//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        vector<bool> visited(adj.size(),false);
        vector<int> ans;
        queue<int> que;
        visited[0]=true;
        que.push(0);
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                int top = que.front();
                que.pop();
                ans.push_back(top);
                for(int j=0;j<adj[top].size();j++){
                    if(!visited[adj[top][j]]){
                        que.push(adj[top][j]);
                        visited[adj[top][j]]=true;
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends