//TODO:                                  DFS  Traversals
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

// Total 6 Combination are Possible :- //Leetcode
// 3 are given below.
// other 3 can be obtained by changing the positions of root->left and root->right.
void Preorder(TreeNode *root){
    if(root==NULL) return;
    cout<<root->val<<" ";  // root
    Preorder(root->left);  // Left
    Preorder(root->right); // right
}

void Inorder(TreeNode *root){
    if(root==NULL) return;
    Inorder(root->left);  // Left
    cout<<root->val<<" "; // root
    Inorder(root->right); // right
}

void Postorder(TreeNode *root){
    if(root==NULL) return;
    Postorder(root->left);   // left
    Postorder(root->right); // right
    cout<<root->val<<" ";  // root
}

int levels(TreeNode *root){
    if(root == NULL)return 0;
    return 1 + max(levels(root->left),levels(root->right));
}
 
void NthLvlTrvsal(TreeNode *root,int curr, int lvl){
    if(root==NULL) return;
    if(curr==lvl){
        cout<<root->val<<" ";
        return;
    }
    NthLvlTrvsal(root->left,curr+1,lvl);
    NthLvlTrvsal(root->right,curr+1,lvl);
}

void NthLvlTrvsalRev(TreeNode *root,int curr, int lvl){
    if(root==NULL) return;
    if(curr==lvl){
        cout<<root->val<<" ";
        return;
    }
    NthLvlTrvsalRev(root->right,curr+1,lvl);
    NthLvlTrvsalRev(root->left,curr+1,lvl);
}

void levlodrTrvsal(TreeNode *root){ //Leetcode
    int maxlvl = levels(root);
    for(int i=1; i<=maxlvl; i++){
        NthLvlTrvsal(root,1,i);    // For Left to right
        // NthLvlTrvsalRev(root,1,i); // For right to left
        cout<<endl;
    }
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
    cout<<endl;
    Inorder(a);
    cout<<endl;
    Postorder(a);
    cout<<endl;

    NthLvlTrvsal(a,1,4);
    cout<<endl;

    levlodrTrvsal(a);
    cout<<endl;

    return 0;
}