//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
    void getDFS(vector<vector<int>> adjList,vector<bool> &visited,int currNode){
        for(int i=0;i<adjList[currNode].size();i++){
            if(!visited[adjList[currNode][i]]){
                visited[adjList[currNode][i]]=true;
                getDFS(adjList,visited,adjList[currNode][i]);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V,false);
        int provinces=0;
        vector<vector<int>> adjList(V,vector<int>(0));
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                provinces++;
                getDFS(adjList,visited,i);
            }
        }
        return provinces;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends