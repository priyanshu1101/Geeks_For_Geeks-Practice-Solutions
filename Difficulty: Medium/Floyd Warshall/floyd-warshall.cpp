//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                    mat[i][j] = mat[i][j]==-1? 10e8:mat[i][j];
                }
            }
        for(int via=0;via<mat.size();via++){
            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                    mat[i][j] = min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }
                for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                    mat[i][j] = mat[i][j]==10e8? -1:mat[i][j];
                }
            }

    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends