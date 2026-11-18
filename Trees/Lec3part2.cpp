//TODO:                      Boundary traversal of a Tree
# include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val = 0;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

};

// Construct a Tree using Queue.
TreeNode* ConstTree(int arr[], int n){ 
    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode*>q;
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
        TreeNode*temp = q.front();
        q.pop(); 
        TreeNode* left;
        TreeNode* right;

        if(arr[i]!=-1) left = new TreeNode(arr[i]);
        else left = NULL;
        if(arr[j]!=-1) right = new TreeNode(arr[j]);
        else right = NULL;

        temp->left = left;
        temp->right = right;

        if(left!=NULL) q.push(left);
        if(right!=NULL) q.push(right);

        i+=2;
        j+=2;
    }
    return root;
}

void LeftBoundary(TreeNode* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->val<<" ";
    if(root->left==NULL)LeftBoundary(root->right);
    else LeftBoundary(root->left);
}

void BottomBoundary(TreeNode* root){ // All leaf Nodes
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL) cout<<root->val<<" ";
    BottomBoundary(root->left);
    BottomBoundary(root->right); 
}

void RightBoundary(TreeNode* root){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL) return;
    if(root->right==NULL)RightBoundary(root->left);
    else RightBoundary(root->right);
    cout<<root->val<<" "; //VIMP - Since we need our result in reverse order so use call ke badd kamm.
}

void Boundary(TreeNode *root){
    LeftBoundary(root);
    cout<<endl;
    BottomBoundary(root);
    cout<<endl;
    RightBoundary(root->right); //VIMP - Always Pass root.right since we have already included root in Left Boundary
}
    
int main(){
    int arr[] = {1,2,3,4,5,-1,6,7,-1,8,-1,9,10,-1,11,-1,12,-1,13,-1,14,15,16,-1,17,-1,-1,18,-1,19,-1,-1,-1,20,21,22,23,-1,24,25,26,27,-1,-1,28,-1,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    TreeNode* root = ConstTree(arr,n);
    Boundary(root);
    return 0;
}