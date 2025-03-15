//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool canIUseThisColor(vector<vector<int>> &adj,vector<int> &colors,int curr,int color){
        for(int adjNode:adj[curr]){
            if(colors[adjNode]==color) return false;
        }
        return true;
    }
    bool colorTraversal(vector<vector<int>> &adj,vector<int> &colors,int m,int curr){
        if(colors.size() ==curr) return true;
        for(int color=1;color<=m;color++){
            if(canIUseThisColor(adj,colors,curr,color)){
                colors[curr]=color;
                if(colorTraversal(adj,colors,m,curr+1)){
                    return true;
                }
                colors[curr]=0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<int> colors(v,0);
        vector<vector<int>> adj(v,vector<int>(0));
        for(auto edge:edges){
            int src=edge.first,des=edge.second;
            adj[src].push_back(des);
            adj[des].push_back(src);
        }
        return colorTraversal(adj,colors,m,0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends