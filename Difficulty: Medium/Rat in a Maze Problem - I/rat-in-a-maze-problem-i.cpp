//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    vector<char> compass={'D','R','U','L'};
    vector<string> ans;
    void traversal(vector<vector<int>> &mat,int i,int j,string subans){
        if(i==mat.size() || j==mat.size() || i<0 || j<0) return;
        if(i==mat.size()-1 && j==mat.size()-1){
            ans.push_back(subans);
            return;
        }
        for(int k=0;k<directions.size();k++){
            int newI=i+directions[k][0],newJ=j+directions[k][1];
            if(newI<mat.size() && newJ<mat.size() && newI>=0 && newJ>=0 && mat[newI][newJ]==1){
                mat[i][j]=0;
                traversal(mat,newI,newJ,subans+compass[k]);
                mat[i][j]=1;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        traversal(mat,0,0,"");
        return ans;
    }
};



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