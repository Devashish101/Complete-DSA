// Array/vector implementation.
# include <bits/stdc++.h>
using namespace std;
class Queue1{
public:
    int f;//front
    int b;//back
    int s;//size
    vector<int> arr;

    Queue1(int val){
        f = 0;
        b = 0;
        s = 0;
        vector<int> v(val);
        arr = v;
    }

    void push(int val){
        if(b==arr.size()){
            cout<<"Queue is Full!"<<"\n";
            return;
        }
        arr[b] = val;
        b++;
        s++;
    }

    void pop(){
        if(s==0){
            cout<<"Queue is Empty!"<<"\n";
            return;
        }
        f++;
        s--;
    }

    int front(){
        if(s==0){
            cout<<"Queue is Empty!"<<"\n";
            return -1;
        }
        return arr[f];
    }

    int back(){
        if(s==0){
            cout<<"Queue is Empty!"<<"\n";
            return -1;
        }
        return arr[b-1];
    }

    int size(){
        return s;
    }
 
    bool empty(){
        if(s==0) return true;
        else false;
    }

    void display(){
        for(int i=f; i<b; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};
    
int main(){
    int val;
    cout<<"Enter the size of your queue :";
    cin>>val;
    Queue1 qu(val);
    qu.push(11);
    qu.push(12);
    qu.push(13);
    qu.push(14);
    qu.push(15); 
    qu.display();
    qu.pop();
    qu.push(16);
    qu.display();
    cout<<qu.size();
    cout<<"\n";
    cout<<qu.front()<<" "<<qu.back()<<"\n";
    
    return 0;
}

// Queue Implementation using LL.
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


// Creating a user defined Queue data Structure
class Queue{
public:
    Node *head;
    Node *tail;
    int size;
    Queue(){
        head = tail = NULL;
        size = 0;
    }

    void push(int val){
        Node * temp = new Node(val);
        if(size==0) head  = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void pop(){
        if(size==0) {
            cout<<"Queue is Already Empty!"<<"\n";
            return;
        }
        else{
            Node *waste = head;
            head = head->next;
            size--;
            delete(waste);//for clearing the delted Node from memory
        }
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
   Queue q;
    q.pop();
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15); 
    q.display();
    q.pop();
    q.push(16);
    q.display();
    cout<<q.size;
    cout<<"\n";
    cout<<q.front()<<" "<<q.back()<<"\n";

}


