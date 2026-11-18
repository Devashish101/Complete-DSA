//TODO: Leetcode 24: Swap Nodes in Pairs =>DONE (Checkout Leetcode) ***
//TODO: Leetcode 83: Remove duplicate from sorted ll DONE(Checkout Leetcode)
//TODO: Leetcode 21: Merge 2 sorted LL =>DONE (Checkout Leetcode)
//TODO: Leetcode 23: Merge K sorted LL =>DONE (Checkout Leetcode)
//TODO: Leetcode 148: Sort LL =>DONE (Checkout Leetcode)
//TODO: Leetcode 86: Partition LL =>DONE (Checkout Leetcode)
//TODO: Leetcode 92: Reverse LL 2 =>DONE (Checkout Leetcode)

# include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;

    Node(int val){
        this->val = val;
        this->next = NULL;    
    }
};

void display(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

//TODO: Leetcode 61: Rotate LL by K DONE
void rotateLL(Node *head,int n){
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    for(int i=0; i<3; i++){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;

    display(head);
}

// Leetcode 206: Reverse LL (Recursive Sol) ,For Iterative sol cheek Leetcode
Node* ReverseLL(Node *head){
    if(head==NULL||head->next==NULL) return head;
    Node* NewHead = ReverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return NewHead;
}

// Leetcode 234: Pallindrome ll T.C - O(n) S.C - O(n) also cheeckout Leetcode
bool ispallindrome(Node *head){
        Node *C = new Node(-1);
        Node *temp = head;
        Node *tempc = C;

        // Creating a copy of LL
        while(temp!=NULL){
            Node *extra = new Node(temp->val);
            tempc->next = extra;
            temp = temp->next;
            tempc = tempc->next; 
        }
        C = C->next;
        // Reversing the Copied LL
        C = ReverseLL(C);
        // Now Comparing the values of LL
        Node *a = C;
        Node *b = head;
        while(b!=NULL){
            if(b->val!=a->val) return false;
            else{
                b = b->next;
                a = a->next;
            }
        }
        return true;
}

int main(){
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    rotateLL(a,2);
    Node* NewHead = ReverseLL(a);
    display(NewHead);
    cout<<ispallindrome(a);
}