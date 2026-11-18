# include <bits/stdc++.h>
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
    
//Leetcode 669. Trim a Binary Search Tree
class Solution {
public:
    void trim(TreeNode*root, int lo, int hi){
        if(root == NULL)return;

        while(root->left != NULL){
            if(root->left->val < lo){
                root->left = root->left->right;
            }
            else if(root->left->val > hi){
                root->left = root->left->left;
            }
            else break;
        }

        while(root->right != NULL){
            if(root->right->val > hi){
                root->right = root->right->left;
            }
            else if(root->right->val < lo){
                root->right = root->right->right;
            }
            else break;
        }

        trim(root->left,lo,hi);
        trim(root->right,lo,hi);
    }
    TreeNode* trimBST(TreeNode* root, int lo, int hi) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        trim(dummy, lo, hi);
        return dummy->left;
    }
};

// leetcode 94. Binary Tree Inorder Traversal -> using morris Traversal
class Solution {
public:
    // Using Morris Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr = root;
        
        while(curr!=NULL){
            if(curr->left != NULL){
        
                TreeNode* pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred =  pred->right;
                }
                if(pred->right == NULL){
                    // Case 1: Linking 
                    pred->right = curr;
                    curr = curr->left;
                }
                else { //pred->right == curr
                    // Case 2: Visit the Node and Unlink
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }

            }
            else{ // curr->left != NULL
                // Step 1: Visit the curr Node
                // step 2: move curr to its right
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};

//Leetcode 114. Flatten Binary Tree to Linked List -> For Method 3 checkout Leetcode

// Method 1:- Making an Array of Preorder and 
// simply attaching other ele in right and NULL in left of root and other ele
class Solution {
public:
    
    void preorder(TreeNode* root, vector<TreeNode*>& pre){
        if(root == NULL)return;
        pre.push_back(root);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
    void flatten(TreeNode* root) {
        if(root == NULL)return;
        vector<TreeNode*>pre;
        preorder(root, pre);
        for(int i=0; i<pre.size()-1; i++){
            pre[i]->left = NULL;
            pre[i]->right = pre[i+1];
        }
        return;
    }
};

// Method 2: Flatten the tree recursively 
// by first flattening the left subtree and then the right subtree.
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)return;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left  = NULL;
        root->right = NULL;
        flatten(l);
        flatten(r);
        root->right = l;
        TreeNode* temp = root;
        while(temp->right != NULL) temp = temp->right;
        temp->right = r;
        return;
    }
};
