//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubSetSumPossible(vector<int>& arr, int target,int i){
        if(target==0) return true;
        if(i==arr.size() || target<0) return false;
        return isSubSetSumPossible(arr,target-arr[i],i+1) || isSubSetSumPossible(arr,target,i+1);
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        return isSubSetSumPossible(arr,target,0);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends