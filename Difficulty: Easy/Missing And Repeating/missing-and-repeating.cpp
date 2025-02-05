//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int totalXorr = 0;
       for(int i=0;i<arr.size();i++) totalXorr^= (i+1)^arr[i];
       int leftMostBit=1;
       int temp=totalXorr;
       while((temp&1)!=1){
           temp=temp>>1;
           leftMostBit=leftMostBit<<1;
       }
       int num1=0,num2=0;
       for(int i=0;i<arr.size();i++){
           if(((i+1)&leftMostBit)==leftMostBit){
               num1=num1^(i+1);
           }
           else num2=num2^(i+1);
           if((arr[i]&leftMostBit)==leftMostBit){
               num1=num1^arr[i];
           }
           else num2=num2^arr[i];
       }
       for(int i=0;i<arr.size();i++){
           if(arr[i]==num1) return {num1,num2};
       }
       return {num2,num1};
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