//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        vector<int> distance(adj.size(),INT_MAX);
        queue<pair<int,int>> que;
        que.push({src,0});
        distance[src]=0;
        while(!que.empty()){
            pair<int,int> top=que.front();
            int currNode = top.first;
            int currDistance = top.second;
            que.pop();
            for(auto adjNode:adj[currNode]){
                int adjNodeValue = adjNode.first;
                int adjNodeDist = adjNode.second;
                if(distance[adjNodeValue]==INT_MAX || distance[adjNodeValue]>currDistance+adjNodeDist){
                    distance[adjNodeValue]=currDistance+adjNodeDist;
                    que.push({adjNodeValue,currDistance+adjNodeDist});
                }
            }
        }
        return distance;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends