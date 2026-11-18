# include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Binary Tree Traversal in Iterative way (using stacks).
void Preorder(TreeNode *root){
    stack<TreeNode*>st;
    if(root!=NULL)st.push(root);
    while(!st.empty()){
        TreeNode *temp = st.top();
        st.pop();

        cout<<temp->val<<" ";

        // VIMP - Always 1st push right then Left.
        if(temp->right != NULL)st.push(temp->right);
        if(temp->left != NULL)st.push(temp->left);
    }
    cout<<endl;
    
}

void Inorder(TreeNode*root){ // VIMP
    stack<TreeNode*>st;
    TreeNode *node = root;

    while(st.size()>0 || node!=NULL){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        }
        else{// node==NULL
            TreeNode* temp = st.top();
            cout<<temp->val<<" ";
            st.pop();
            node = temp->right;
        }
    }
    cout<<endl;

}

void Postorder(TreeNode *root){ //Using 2 Stacks, can also be done via 1 stack and 1 vector.
    stack<TreeNode*>st;
    stack<int>hlpr;
    if(root!=NULL) st.push(root);
    while(st.size()>0){
        TreeNode* temp = st.top();
        st.pop();

        hlpr.push(temp->val);
        if(temp->left != NULL)st.push(temp->left);
        if(temp->right != NULL)st.push(temp->right);
    }
    while(hlpr.size()>0){
        cout<<hlpr.top()<<" ";
        hlpr.pop();
    }
    cout<<endl;
}
    
int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);
    TreeNode *h = new TreeNode(8);
    TreeNode *i = new TreeNode(9);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = h;
    e->left = f;
    e->right = g;
    h->left = i;

    Preorder(a);
    Inorder(a);
    Postorder(a);

}