# include <bits/stdc++.h>
using namespace std;

class Node{ 
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};


// Creating a user defined LL data Structure
class LinkedList{
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val){
        Node * temp = new Node(val);
        if(size==0) head  = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int val){
        Node * temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtidx(int idx,int val){
        if(idx<0 || idx>size) cout<<"Invalid Index"<<endl;
        else if(idx == 0) insertAtHead(val);
        else if(idx == size) insertAtTail(val);
        else{
            Node *ptr = new Node(val);
            Node *temp = head;
            for(int i=0; i<idx-1; i++){
                temp = temp->next;
            }
            ptr->next = temp->next;
            temp->next = ptr;
            size++;
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
            Node *temp = head;
            for(int i=0; i<idx; i++){
                temp = temp->next;
            }
            return temp->val;
        }

    }

    void deleteAtHead(){
        if(size==0) {
            cout<<"Linked List is Already Empty!";
            return;
        }
        else{
            head = head->next;
            size--;
        }
    }

    void deleteAtTail(){
        if(size==0) {
            cout<<"Linked List is Already Empty!";
            return;
        }
        Node *temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
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
            size--;
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
   LinkedList ll;
   ll.insertAtTail(10);
   ll.insertAtTail(30);
   ll.display();
   cout<<ll.size<<endl;
   ll.insertAtTail(50);
   ll.display();
   cout<<ll.size<<endl;

   ll.insertAtHead(90);
   ll.insertAtHead(70);
   ll.display();
   cout<<ll.size<<endl;

   ll.insertAtidx(4,40);
   ll.display();
   cout<<ll.size<<endl;

   cout<<ll.getAtIdx(4)<<endl;
   cout<<ll.getAtIdx(7)<<endl;

   ll.deleteAtHead();
   ll.display();

   ll.deleteAtTail();
   ll.display();

   ll.deleteAtIdx(2);
   ll.display();
}