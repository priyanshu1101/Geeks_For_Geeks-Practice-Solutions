//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void ansFinder(long long i,long long prevVAlue,long long n,vector<long long>& ans){
        long long value = i*prevVAlue;
        if(value>n) return;
        ans.push_back(value);
        ansFinder(i+1,value,n,ans);
    }
    vector<long long> factorialNumbers(long long n) {
        vector<long long> ans;
        ansFinder(1,1,n,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends