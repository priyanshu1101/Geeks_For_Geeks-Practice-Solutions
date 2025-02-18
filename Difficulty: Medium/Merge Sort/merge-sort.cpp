//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void mergeTwoSorted(vector<int>& arr,int l,int mid,int r){
        int s1=l,e1=mid,s2=mid+1,e2=r;
        vector<int> subAns;
        int tempStart = s1;
        while(s1<=e1 && s2<=e2){
            if(arr[s1]<arr[s2]){
                subAns.push_back(arr[s1++]);
            }
            else{
                subAns.push_back(arr[s2++]);
            }
        }
        while(s1<=e1){
            subAns.push_back(arr[s1++]);
        }
        while(s2<=e2){
            subAns.push_back(arr[s2++]);
        }
        for(int i=0;i<subAns.size();i++){
            arr[tempStart++] = subAns[i];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        mergeTwoSorted(arr,l,mid,r);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends