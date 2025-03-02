//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* mergeTwoSortedLinkedList(Node* root1,Node* root2){
        Node* newHead=new Node(-1);
        Node* tail=newHead;
        while(root1 && root2){
            if(root1->data<root2->data){
                tail->bottom=root1;
                root1=root1->bottom;
            }else{
                tail->bottom=root2;
                root2=root2->bottom;
            }
            tail=tail->bottom;
            tail->bottom=NULL;
        }
        if(root1){
            tail->bottom=root1;
        }
        if(root2){
            tail->bottom=root2;
        }
        return newHead->bottom;
    }
    Node *flatten(Node *root) {
        Node* newHead = root;
        Node* nextNode = root->next;
        while(nextNode){
            newHead=mergeTwoSortedLinkedList(newHead,nextNode);
            nextNode=nextNode->next;
        }
        return newHead;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends