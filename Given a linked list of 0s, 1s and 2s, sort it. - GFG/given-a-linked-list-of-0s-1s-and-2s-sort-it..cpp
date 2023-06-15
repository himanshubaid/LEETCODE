//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{  
    public:
    Node* mergesortedList(Node* l1,Node* l2)
    {
        if(l1==NULL)
        return l2;
        if(l2==NULL)
        return l1;
        Node* ans=new Node(0);
        Node* curr=ans;
        while(l1 && l2)
        {
            if(l1->data<=l2->data)
            {
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1)
        curr->next=l1;
        if(l2)
        curr->next=l2;
        return ans->next;
    }
    Node* midterm(Node* head)
    {
        Node* slow=head;
        Node* fast=head;

        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* sortList(Node* head)
    {
        if(head==NULL||head->next==NULL)
           return head;
        
        Node* mid=midterm(head);
        Node* newhead=mid->next;
        mid->next=NULL;

        Node* leftsort=sortList(head);
        Node* rightsort=sortList(newhead);

        return mergesortedList(leftsort,rightsort);        
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        return sortList(head);
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends