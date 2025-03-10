//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class UnionSet{
    public:
    vector<int> size;
    vector<int> parent;
    UnionSet(int V){
        parent.resize(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    void addToUnion(int node,int headNode){
        if(findParent(node)==findParent(headNode)) return;
        else parent[findParent(node)]=findParent(headNode);
    }
};

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        set<pair<int,pair<int,int>>> st;
        for(int i=0;i<V;i++){
            for(auto adjNodeData:adj[i]){
                int src=i,des = adjNodeData[0], distance = adjNodeData[1];
                if(st.find({distance,{des,src}})==st.end())
                    st.insert({distance,{src,des}});
            }
        }
        int ans=0;
        UnionSet* obj = new UnionSet(V);
        for(auto itr=st.begin();itr!=st.end();itr++){
            pair<int,pair<int,int>> topPair=*itr;
            int src=topPair.second.first,des = topPair.second.second, distance = topPair.first;
            if(obj->findParent(src)==obj->findParent(des)) continue;
            else{
                obj->addToUnion(src,des);
                ans+=distance;
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