//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void sortOnce(vector<int>& arr,int start,int till){
        if(start>=till) return;
        if(arr[start]>arr[till]) swap(arr[start],arr[till]);
        sortOnce(arr,start+1,till);
    }
    void bubbleSort(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            sortOnce(arr,0,arr.size()-i-1);
        }
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
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

        Solution ob;

        ob.bubbleSort(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends