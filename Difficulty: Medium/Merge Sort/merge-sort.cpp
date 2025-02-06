//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void mergeSortedArray(vector<int>& arr,int start,int mid,int end){
        // array1 start-mid;
        // array2 mid+1-end;
        vector<int> subans;
        int aStart=start;
        int aEnd=mid;
        int bStart=mid+1;
        int bEnd=end;
        while(aStart<=aEnd && bStart<=bEnd){
            if(arr[aStart]<arr[bStart]){
                subans.push_back(arr[aStart++]);
            }
            else subans.push_back(arr[bStart++]);
        }
        while(aStart<=aEnd) subans.push_back(arr[aStart++]);
        while(bStart<=bEnd) subans.push_back(arr[bStart++]);
        for(int i=0;i<subans.size();i++){
            arr[start+i]=subans[i];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
       if(l>=r) return;
       int mid=(l+r)/2;
       mergeSort(arr,l,mid);
       mergeSort(arr,mid+1,r);
       mergeSortedArray(arr,l,mid,r);
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