// Done in Last Lecture i.e Lecture 4.
//TODO: Leetcode 725: Split LL in parts =>DONE (Checkout Leetcode)✅
//TODO: Leetcode 2058: Find the min and max No. of Nodes btw Critical Points =>DONE (Checkout Leetcode)
//TODO: Leetcode 2074: Reverse Nodes in even length Groups =>DONE (Checkout Leetcode)
//TODO: Leetcode 138: Copy List With Random Pointer =>DONE (Checkout Leetcode)
//TODO: Leetcode 438: Flatten a Multilevel Doubly LL  =>DONE (Checkout Leetcode)

# include <bits/stdc++.h>
using namespace std;

class Node{ 
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// Creating a user defined DLL data Structure
class DLL{
public:
    int size;
    Node *head;
    Node *tail;
    DLL(){
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val){
        Node * temp = new Node(val);
        if(size==0) head  = tail = temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int val){
        Node * temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertAtidx(int idx,int val){
        if(idx<0 || idx>size) cout<<"Invalid Index"<<endl;
        else if(idx == 0) insertAtHead(val);
        else if(idx == size) insertAtTail(val);
        else{
            Node *t = new Node(val);
            Node *temp = head;
            for(int i=0; i<idx-1; i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            t->prev = temp;
            t->next->prev = t;
            size++;
        }
    }

    void deleteAtHead(){
        if(size==0) {
            cout<<"Linked List is Already Empty!";
            return;
        }
        else if(size==1){
            head = tail = NULL;
            size--;
        }
        else{
            head = head->next;
            head->prev = NULL;
            size--;
        }
    }

    void deleteAtTail(){
        if(size==0) {
            cout<<"Linked List is Already Empty!";
            return;
        }
        else if(size==1){
           deleteAtHead();
           return;
        }
        Node *temp = tail->prev;
        temp->next = NULL;
        tail = temp; 
        size--;
    }

    void deleteAtIdx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid idx";
            return;
        }
        else if(idx==0) deleteAtHead();
        else if(idx==size-1) deleteAtTail();
        else{
            Node *temp = head;
            for(int i=0; i<idx-1; i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp;
            size--;
        }
    }

    int getAtIdx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid idx";
            return -1;
        }
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else{
            if(idx<=size/2){
                Node *temp = head;
                for(int i=0; i<idx; i++){
                    temp = temp->next;
                }
                return temp->val;
            }
            else{
                Node *temp = tail;
                for(int i=size-1; i>idx; i--){
                    temp = temp->prev;
                }
                return temp->val;
            }
            
        }

    }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    DLL list;
    list.insertAtTail(10); 
    list.deleteAtHead();
    list.insertAtTail(20); 
    list.insertAtTail(30);
    list.display();
    list.insertAtTail(40);
    list.deleteAtTail(); 
    list.display();
    list.insertAtHead(11);
    list.display();
    list.insertAtidx(2,25);
    list.display();
    list.deleteAtIdx(3);
    list.display();
    list.insertAtTail(60);
    list.insertAtTail(80);
    list.insertAtTail(90);
    list.display();
    cout<<list.getAtIdx(5);
}

