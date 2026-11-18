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

void LvlordTrav(TreeNode *root){ // using Queue BFS
    queue<TreeNode *>q;
    q.push(root);
    while(q.size() != 0){
        TreeNode *temp = q.front();
        cout<<temp->val<<" ";
        q.pop();
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

TreeNode* ConstTree(int arr[], int n){ // Construct a Tree using Queue.
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

int main(){
    int arr[] = {1,2,3,4,5,-1,8,-1,-1,6,7,9,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    TreeNode *root = ConstTree(arr,n);
    LvlordTrav(root);
    
}