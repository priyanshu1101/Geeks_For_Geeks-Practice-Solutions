//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        vector<int> shortestPathArr(adj.size(),-1);
        queue<int> que;
        que.push(src);
        shortestPathArr[src]=0;
        int jump=0;
        while(!que.empty()){
            int size = que.size();
            jump++;
            while(size--){
                int top = que.front();
                que.pop();
                for(int adjNode:adj[top]){
                    if(shortestPathArr[adjNode]==-1){
                        shortestPathArr[adjNode]=jump;
                        que.push(adjNode);
                    }
                }
            }
        }
        return shortestPathArr;
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends