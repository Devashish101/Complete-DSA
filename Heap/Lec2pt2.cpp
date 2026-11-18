// TODO: BST to MaxHeap.
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root, vector<int> &arr){ // Reverse inorder
    if(root == NULL) return;

    inorder(root->right, arr);
    arr.push_back(root->val);
    inorder(root->left, arr);
}

void preorder(Node* root, vector<int> &arr, int &i){
    if(root == NULL) return;

    root->val = arr[i++];
    preorder(root->left, arr, i);
    preorder(root->right, arr, i);
}

void levelordertrav(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout << endl;
}

int main(){
    Node *a = new Node(10);
    Node *b = new Node(5);
    Node *c = new Node(16);
    Node *d = new Node(1);
    Node *e = new Node(8);
    Node *f = new Node(12);
    Node *g = new Node(20);

    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = f; c->right = g;

    vector<int> arr;

    inorder(a, arr);

    cout << "Before conversion:\n";
    levelordertrav(a);

    int i = 0;
    preorder(a, arr, i);

    cout << "After conversion:\n";
    levelordertrav(a);

    return 0; 
}

// TODO: Check if a given Binary Tree is a MaxHeap or Not.
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void levelordertrav(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout << endl;
}

// Check Max Heap Property
bool isMax(Node* root){
    if(root == NULL) return true;

    if(root->left != NULL && root->val < root->left->val)
        return false;

    if(root->right != NULL && root->val < root->right->val)
        return false;

    return isMax(root->left) && isMax(root->right);
}

// Check Complete Binary Tree Property
bool isCBT(Node* root){
    if(root == NULL) return true;

    queue<Node*> q;
    q.push(root);

    bool nullFound = false;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            nullFound = true;
        }
        else{
            // If we see a non-null node after a null node,
            // tree is not complete.
            if(nullFound) return false;

            q.push(curr->left);
            q.push(curr->right);
        }
    }

    return true;
}

// Check if tree is a Max Heap
bool isHeap(Node* root){
    return isCBT(root) && isMax(root);
}

int main(){

    Node *a = new Node(20);
    Node *b = new Node(15);
    Node *c = new Node(10);
    Node *d = new Node(8);
    Node *e = new Node(11);
    Node *f = NULL;
    Node *g = new Node(6);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    levelordertrav(a);

    cout << "Is Max Property: " << isMax(a) << endl;
    cout << "Is Complete Binary Tree: " << isCBT(a) << endl;
    cout << "Is Max Heap: " << isHeap(a) << endl;

    return 0;
}