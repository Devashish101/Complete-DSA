//TODO: Implementation of Stack in Different Data Structures✅

// Array Implementation
#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int arr[5];
    int idx = 0;

    void push(int val) {
        if (idx == sizeof(arr)/sizeof(arr[0])-1) { // Overflow Condition
            cout << "Stack is full\n";
            return;
        }
        arr[idx++] = val;
    }

    void pop() {
        if (idx == 0) { // underflow Condition
            cout << "Stack is Empty!\n";
            return;
        }
        idx--;
    }

    int top() {
        if (idx == 0) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return arr[idx - 1];
    }

    int size() {
        return idx;
    }

    void display() {
        for (int i = 0; i < idx; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // cout << "Size: " << st.size() << endl;

    st.pop();

    // cout << "Size after pop: " << st.size() << endl;
    cout << "Stack elements: ";
    st.display();

    cout << "Top element: " << st.top() << endl;

    return 0;
}


// Vector Implementation
#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    vector<int> v;
    void push(int val) { //NO overflow Condition(since vector has unlimited size)
        v.push_back(val);
    }

    void pop() {
        if (v.size() == 0) { //underflow Condition
            cout << "Stack is Empty!\n";
            return;
        }
        v.pop_back();
    }

    int top() {
        if (v.size() == 0) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return v[v.size()-1];
    }

    int size() {
       v.size();
    }

    void display() {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // cout << "Size: " << st.size() << endl;

    st.pop();

    // cout << "Size after pop: " << st.size() << endl;
    cout << "Stack elements: ";
    st.display();

    cout << "Top element: " << st.top() << endl;

    return 0;
}

# include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* Next;

    Node(int val){
        this->val = val;
        Next = NULL;
    }
};

class Stack{
public:
    Node* head;
    int size;

    Stack(){
        head = NULL;
        size = 0;
    }

    void push(int val){ // Naya Node banao usko head se connect karo aur phir head ko piche le aao.
        Node *temp = new Node(val);
        temp->Next = head;
        head = temp;
        size++;
    }

    void pop(){
        if(size==0){
            cout<<"Stack is Empty!"<<endl;
            return;
        }
        head = head->Next;
        size--;
    }

    int top(){
        if(size==0){
            cout<<"Stack is Empty!";
            return -1;
        }
        cout<<head->val<<endl;
    }

    void print(Node* temp){
        if(temp==NULL) return;
        print(temp->Next);
        cout<<temp->val<<" ";
    }

    void display(){
        Node *temp = head;
        print(temp);
        cout<<endl;
    }
};

int  main(){
    Stack st;
    st.pop();
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.display();
    cout<<"Current Size is:"<<st.size<<"\n";
    st.top();
    st.display();

}

