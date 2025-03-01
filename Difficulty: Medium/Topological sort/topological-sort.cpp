//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int> indegree(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            for(int adjNode:adj[i]){
                indegree[adjNode]++;
            }
        }
        queue<int> que;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) que.push(i);
        }
        vector<int> topologicalSortAns;
        while(!que.empty()){
            int top=que.front();
            topologicalSortAns.push_back(top);
            que.pop();
            for(int adjNode:adj[top]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0){
                    que.push(adjNode);
                }
            }
        }
        return topologicalSortAns;
    }
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends