//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int a_b=0;
        int a2_b2=0;
        for(int i=0;i<arr.size();i++){
            a_b+=(i+1)-arr[i];
            a2_b2+=((i+1)*(i+1))-(arr[i]*arr[i]);
        }
        a2_b2/=a_b;
        int a = (a_b+a2_b2)/2;
        int b = a - a_b;
        return {b,a};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends