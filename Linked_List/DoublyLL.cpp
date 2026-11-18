//                                                              Doubly Linked List(lec4)
# include <bits/stdc++.h>
using namespace std;

class Node{
public:

    Node *prev;
    int val;
    Node *Next;

    Node(int val){
        this->val = val;
        this->prev = NULL;
        this->Next = NULL;
    }

};

//Traversing the Doubly LL using Next Ptr
void displaybyHead(Node *head){ 
    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->Next;
    }
    cout<<endl;
}

// FIXME: Displaying the LL With the help of Recursion
void displayRecursion(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    displayRecursion(head->Next);
}

// FIXME:Traversing the Doubly LL in Reverse order using prev Ptr
void displaybyTail(Node *tail){ 
    while(tail!=NULL){
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}

// TODO: NOTE -> If any node of LL is given then we can traverse through the entire LL using nodes prev and next ptrs.
void traverseLL(Node *nodex){
    // Method 1 : for finding in serial order
    while(nodex->prev != NULL){ //finding the head node
        nodex = nodex->prev;
    }
    displaybyHead(nodex); // at this point nodex is at head

    // Method 2  : for printing in reverse order
    while(nodex->Next != NULL){ //finding the tail node
        nodex = nodex->Next;
    }
    displaybyTail(nodex); // at this point nodex is at tail
}

int main(){
    // NULL <=> 10 <=> 20 <=> 30 <=> 40 <=> 50 <=> NULL
    Node * a = new Node(10);
    Node * b = new Node(20);
    Node * c = new Node(30);
    Node * d = new Node(40);
    Node * e = new Node(50);

    a->Next = b;
    b->Next = c;
    c->Next = d;
    d->Next = e;

    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;

    displaybyHead(a);
    displaybyTail(e);
    traverseLL(c);
}