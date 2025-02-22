//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int gcdCal(int a,int b){
        if(a==0 || b==0) return a==0? b:a;
        if(a>b) return gcdCal(a%b,b);
        else return gcdCal(b%a,a);
    }
    vector<int> lcmAndGcd(int a, int b) {
        int gcd=gcdCal(a,b);
        return {a/gcd*b,gcd};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends