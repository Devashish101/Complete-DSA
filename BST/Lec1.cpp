// Leetcode 700. Search in a Binary Search Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* searchBST(TreeNode* root, int val) {

    if(root == NULL)
        return NULL;

    else if(root->val == val)
        return root;

    else if(root->val > val)
        return searchBST(root->left, val);

    else
        return searchBST(root->right, val);
}

int main() {

    // [4,2,7,1,3]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;
    TreeNode* ans = searchBST(root, val);

    if(ans == NULL)
        cout << "NULL";
    else
        cout << "Found: " << ans->val;
}

// 701. Insert into a Binary Search Tree
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)return new TreeNode(val);
        else if(root->val > val){ // Go left
            if(root->left == NULL){ // attach it here
                root->left = new TreeNode(val);
            }else{ 
                insertIntoBST(root->left, val);
            } 
        }
        else{ // Go right
            if(root->right == NULL){ // attach it here
                root->right = new TreeNode(val);
            }else{ 
                insertIntoBST(root->right, val);
            } 
        }
        return root;
    }
};

//Leetcode 235. Lowest Common Ancestor of a Binary Search Tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val)return root;
        else if(root->val > p->val && root->val < q->val)return root;
        else if(root->val > q->val && root->val < p->val)return root;
        else if(root->val > p->val && root->val > q->val){ // Go Left
            return lowestCommonAncestor(root->left,p,q);
        }
        else return lowestCommonAncestor(root->right,p,q); // Go Right
    }
};

// Leetcode 98. Validate Binary Search Tree
// Another Way is Inorder checkout Leetcode
class Solution {
public:
    long long maxTree(TreeNode* root){
        if(root == NULL)return LLONG_MIN;
        return max((long long)(root->val),max(maxTree(root->left),maxTree(root->right)));
    }
    long long minTree(TreeNode* root){
        if(root == NULL)return LLONG_MAX;
        return min((long long)(root->val),min(minTree(root->left),minTree(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        else if((long long) (root->val) <= maxTree(root->left))return false;
        else if((long long)(root->val) >= minTree(root->right))return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};

// 1038. Binary Search Tree to Greater Sum Tree
class Solution {
public:
    void revInorder(TreeNode* root,int &sum){
        if(root == NULL)return;

        revInorder(root->right,sum);

        root->val += sum;
        sum = root->val;
        
        revInorder(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        revInorder(root,sum);
        return root;
    }
};

// 108. Convert Sorted Array to Binary Search Tree
class Solution {
public:
    TreeNode* inorder(int lo, int hi, vector<int>& nums){
        if(lo > hi)return NULL;

        int mid = lo+(hi-lo)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = inorder(lo, mid-1, nums);
        root->right = inorder(mid+1, hi, nums);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        int mid = lo+(hi-lo)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = inorder(lo, mid-1, nums);
        root->right = inorder(mid+1, hi, nums);
        return root;
    }
};

// 1008. Construct Binary Search Tree from Preorder Traversal
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)return new TreeNode(val);
        else if(root->val > val){ // Go left
            if(root->left == NULL){ // attach it here
                root->left = new TreeNode(val);
            }else{ 
                insertIntoBST(root->left, val);
            } 
        }
        else{ // Go right
            if(root->right == NULL){ // attach it here
                root->right = new TreeNode(val);
            }else{ 
                insertIntoBST(root->right, val);
            } 
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n = pre.size();
        TreeNode* root = new TreeNode(pre[0]);
        for(int i=1; i<n; i++){
            insertIntoBST(root,pre[i]);
        }
        return root;
    }
};
