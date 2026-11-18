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

void display(TreeNode *root){
    if(root==NULL)return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}

int Tree_sum(TreeNode *root,int &sum){ //Method 1.
    if(root == NULL) return 0;
    sum+=root->val;
    Tree_sum(root->left,sum);
    Tree_sum(root->right,sum);
    return sum;
}

int TreeSum(TreeNode *root){ //Method 2.
    if(root==NULL) return 0;
    int lstsum = TreeSum(root->left);   //Sum of left Sub Tree
    int Rstsum = TreeSum(root->right); //Sum of right sub Tree
    return root->val+lstsum+Rstsum;
}

int TreeSize(TreeNode *root){
    if(root == NULL) return 0;
    return 1+TreeSize(root->left)+TreeSize(root->right);
}

int MaxNodeval(TreeNode *root,int &max){ //Method 1.
    if(root==NULL)return max;
    if(root->val > max) max = root->val;
    MaxNodeval(root->left,max);
    MaxNodeval(root->right,max);
}

int maxval(TreeNode *root){ //Method 2.
    if(root == NULL) return INT_MIN;
    int leftMax = max(root->val,maxval(root->left));
    int rightMax = max(root->val,maxval(root->right));
    return max(leftMax,rightMax);
}

int level(TreeNode *root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}

//TODO: Leetcode 543.
int maxDia = 0;
int Diameter(TreeNode *root){
    if(root==NULL) return 0;
    int dia = (level(root->left)+level(root->right));
    maxDia = max(dia,maxDia);
    Diameter(root->left);
    Diameter(root->right);
    return maxDia;
}

//TODO: Leetcode 226.
TreeNode* InvertbinaryTree(TreeNode* root){
    if(root==NULL) return NULL;

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    InvertbinaryTree(root->left);
    InvertbinaryTree(root->right);

    return root;

}

//TODO: Leetcode 257. G.Q
void Binarytreepath(TreeNode *root,string str,vector<string> &ans){
    if(root==NULL)return;

    str+=to_string(root->val);
    if(root->left==NULL && root->right==NULL){
        ans.push_back(str);
        return;
    }

    Binarytreepath(root->left,str+="->",ans);
    Binarytreepath(root->right,str,ans);
}

int main(){  
    TreeNode *a = new TreeNode(5);
    TreeNode *b = new TreeNode(4);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(6);
    TreeNode *e = new TreeNode(2);
    TreeNode *f = new TreeNode(1);
    TreeNode *g = new TreeNode(8);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = g;
    c->right = f;

    display(a);
    cout<<"\n";

    int sum = 0;
    Tree_sum(a,sum);
    cout<<sum<<"\n";

    cout<<TreeSize(a)<<endl;

    int max = INT_MIN;
    MaxNodeval(a,max);
    cout<<max<<endl;

    cout<<level(a)<<endl;
    cout<<Diameter(a)<<endl;

    InvertbinaryTree(a);
    display(a);
    cout<<endl;

    vector<string>ans;
    Binarytreepath(a,"",ans);

    for(auto ele:ans){
        cout<<ele<<" ";
    }

    return 0;
}