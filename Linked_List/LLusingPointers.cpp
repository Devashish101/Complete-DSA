# include <bits/stdc++.h>
using namespace std;

class Node{ // Linked list Node
public:
    int val;
    Node* next;

    // Forming a Constructor
    Node(int val){
        this->val = val;
        this->next = NULL; //Putting By default NULL vlues in next part of all node  
    }
};

// FIXME: Traversing/Displaying the LL With the help of Pointers
void display(Node* head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

// FIXME: Displaying the LL With the help of Recursion
void displayRecursion(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    displayRecursion(head->next);
}

// FIXME: Displaying the LL in Reverse order With the help of Recursion
void Reversedisplay(Node* head){
    if(head==NULL) return;
    Reversedisplay(head->next);
    cout<<head->val<<" ";
}

// FIXME: Finding the size of the LL With the help of Pointers
int size(Node * head){
    Node * temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtEnd(Node* head,int val){
    Node * t = new Node(val);
    while(head->next != NULL) head = head->next;
    head->next = t;
}

int main(){

    //TODO: Inserting Values in the Nodes and Connecting the LL With the help of Constructor and Pointers
    Node *a = new Node (10);
    Node *b = new Node (20);
    Node *c = new Node (30);
    Node *d = new Node (40);
    Node *e = new Node (50);
    a->next = b;
    b->next = c; 
    c->next = d;
    d->next = e;

    // cout<<a->next->next->next->val<<endl;

    display(a); 
    cout<<endl;
    insertAtEnd(a,80);
    display(a); 

    // displayRecursion(a); 

    // Reversedisplay(a); 

    // cout<<"Size of LL is "<< size(a);

}