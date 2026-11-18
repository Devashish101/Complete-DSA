# include <iostream>
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
    cout<<endl;
}

// Leetcode: 237 Delete Node value in a LL
Node* deletenodeval(Node *head, int targetval){
    if(head->val == targetval){ 
        head = head->next;
        return head;
    }
    Node *temp = head;
    while(temp->next->val != targetval){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}
// Leetcode 876: Middle of the LL
// Incase of odd len of LL - only 1 middle
// Incase of even len of LL - 2 middle (1st Middle and 2nd Middle).

Node* leftmiddle(Node *head){
    Node* slow = head;    
    Node* fast = head; 
    while(fast->next->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
    }  
    return slow; 
}

//TODO: Leetcode 19: Delete the Nth Node from the end of the LL
Node* deleteNthnode(Node *head, int n){
    Node *temp  = head;
    int size = 0;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    if(size==n){
        head = head->next;
        return head;
    }

    temp = head;
    for(int i=1; i<size-n; i++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}

// TODO: Checkout
// Leetcode 160: Intersection of LL =>Done
// Leetcode 141: LL cycle =>Done
// Leetcode 142: LL cycle || =>Done

int main(){
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *f = new Node(60);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    // Node *head = a;
    // display(head);
    // head = deletenodeval(head,10);
    // display(head);

    // Node *ans = leftmiddle(a);
    // cout<<ans->val<<endl;

    Node *ans1 = deleteNthnode(a,2);
    display(a);
    cout<<ans1->val;
}


