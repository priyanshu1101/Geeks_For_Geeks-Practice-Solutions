//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
        vector<bool> visited(V,false);
        int sum=0;
        que.push({0,0});
        while(!que.empty()){
            pair<int,int> top = que.top();
            que.pop();
            int dist = top.first, node = top.second;
            if(visited[node]) continue;
            visited[node]=true;
            sum+=dist;
            for(auto adjNodePair:adj[node]){
                int adjNode=adjNodePair[0],distance = adjNodePair[1];
                if(!visited[adjNode]){
                    que.push({distance,adjNode});
                }
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends