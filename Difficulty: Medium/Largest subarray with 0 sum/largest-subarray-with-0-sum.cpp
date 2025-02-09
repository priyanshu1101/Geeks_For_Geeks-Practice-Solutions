//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int ans=0;
        vector<int> continuousSumArr(arr.size(),0);
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            continuousSumArr[i]=sum;
        }
        unordered_map<int,int> mp={{0,0}};
        for(int i=0;i<continuousSumArr.size();i++){
            if(mp.find(continuousSumArr[i])!=mp.end()){
                ans=max(ans,i+1-mp[continuousSumArr[i]]);
            }else{
                mp[continuousSumArr[i]]=i+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends