// Designing / Implementing Deque(Doubly Ended Queue) with DLL.
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


// Creating a user defined Deque using DLL data Structure
class Deque{
public:
    int size;
    Node *head;
    Node *tail;
    Deque(){
        head = tail = NULL;
        size = 0;
    }

    void pushBack(int val){
        Node * temp = new Node(val);
        if(size==0) head  = tail = temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void pushFront(int val){
        Node * temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void popFront(){
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

    void popBack(){
        if(size==0) {
            cout<<"Linked List is Already Empty!";
            return;
        }
        else if(size==1){
           popFront();
           return;
        }
        Node *temp = tail->prev;
        temp->next = NULL;
        tail = temp; 
        size--;
    }

    int front(){
        if(size==0){
            cout<<"Queue is Empty!"<<"\n";
            return -1;
        }
        return head->val;
    }

    int back(){
        if(size==0){
            cout<<"Queue is Empty!"<<"\n";
            return -1;
        }
        return tail->val;
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
    Deque qu;
    qu.pushBack(10); 
    qu.popFront();
    qu.pushBack(20); 
    qu.pushBack(30);
    qu.pushBack(40);
    qu.display();
    qu.popBack(); 
    qu.display();
    qu.pushFront(11);
    qu.display();
    qu.pushBack(60);
    qu.pushBack(80);
    qu.pushFront(10);
    qu.display();
    cout<<qu.front()<<" "<<qu.back()<<"\n";
    cout<<qu.size;
}

