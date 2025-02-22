//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> ans;
    vector<pair<int,int>> directions={{-1,0},{0,-1},{1,0},{0,1}};
    vector<char> dir = {'U','L','D','R'};
    void ratInAMaze(vector<vector<int>> &mat,int i,int j,string subans){
        if(i>=mat.size() || i<0 || j>=mat[0].size() || j<0) return;
        if(i==mat.size()-1 && j==mat[0].size()-1){
            ans.push_back(subans);
            return;
        }
        for(int k=0;k<directions.size();k++){
            int indexi = i+directions[k].first,indexj=j+directions[k].second;
            if(indexi<mat.size() && indexj<mat[0].size() && mat[indexi][indexj]==1){
                mat[i][j]=-1;
                ratInAMaze(mat,indexi,indexj,subans+dir[k]);
                mat[i][j]=1;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        ratInAMaze(mat,0,0,"");
        return ans;
    }
};
// [[1,1,1,0,1],
//  [1,0,1,1,1],
//  [0,0,1,1,1],
//  [1,0,0,1,1],
//  [1,0,0,0,1]]


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends