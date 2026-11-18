# include <bits/stdc++.h>
using namespace std;

class Node{ // Linked list Node
public:
    int val;
    Node* next;

    // Forming a Constructor
    Node(int v){
        val = v;
        this->next = NULL; //Putting By default NULL values in next part of all node  
    }
};
     

int main(){

//TODO: Inserting Values in the Nodes of a LL Without Constructor
    // Node a;
    // a.val = 10;
    // Node b;
    // b.val = 20;
    // Node c;
    // c.val = 30;
    // Node d;
    // d.val = 40;

//TODO: Inserting Values in the Nodes of a LL With the help of Constructor
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    // cout<<a.val<<" "<<a.next<<endl;
    

//TODO: Forming a LL or Connecting the Nodes
    a.next = &b;
    b.next = &c;
    c.next = &d;
    
    //Printing the value with the help of pointer(Changing of value is also possible)
    /*Method 1 */ //cout<<(*(a.next)).val<<endl; 
    /*Method 2 */ //cout<<(a.next)->val<<endl; 
    /*Method 3 */ //cout<<b.val<<endl; //Without using the pointer


    // Changing the Value
    /* b.next->val = 70;*///changing the value of C
    /* cout<<b.next->val<<"\n";*///Printing the value of C

    // printing the value of d with the help of a and next pointer
    // cout<<(((a.next)->next)->next)->val;


//TODO: Traversing the Linked List
    Node temp = a;
    while(1){
        cout<<temp.val<<" ";
        if(temp.next==NULL)break;
        temp = *(temp.next);
    }

    return 0;
}