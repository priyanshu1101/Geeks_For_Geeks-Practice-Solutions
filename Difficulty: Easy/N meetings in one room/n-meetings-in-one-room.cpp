//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> record;
        for(int i=0;i<start.size();i++){
            record.push_back({end[i],start[i]});
        }
        sort(record.begin(),record.end());
        int totalMeetingPossible=0;
        int endTime=-1;
        for(int i=0;i<record.size();i++){
            if(record[i].second>endTime){
                endTime=record[i].first;
                totalMeetingPossible++;
            }
        }
        return totalMeetingPossible;
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
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends