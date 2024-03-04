//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<Node*,Node*> parent;
    void parentRecord(Node* root){
        if(!root) return;
        if(root->left) parent[root->left]=root;
        if(root->right) parent[root->right]=root;
        parentRecord(root->left);
        parentRecord(root->right);
    }
    Node* targetFinder(Node* root,int target)
    {
        if(!root) return NULL;
        if(root->data==target) return root;
        Node* left=targetFinder(root->left,target);
        return left==NULL? targetFinder(root->right,target):left;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        parentRecord(root);
        int ans=0;
        queue<Node*> que;
        unordered_map<Node*,bool> visited;
        Node* targetNode=targetFinder(root,target);
        que.push(targetNode);
        visited[targetNode]=true;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                Node* temp=que.front();
                que.pop();
                if(temp->left && !visited[temp->left]){
                    que.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right]){
                    que.push(temp->right);
                    visited[temp->right]=true;
                }
                if(parent[temp] && !visited[parent[temp]]){
                    que.push(parent[temp]);
                    visited[parent[temp]]=true;
                }
            }
            ans++;
        }
        return ans-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends