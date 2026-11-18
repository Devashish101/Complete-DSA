// Predecessor and Succesor of the given key in a BST (Key Must Exist in the BST).
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

vector<TreeNode*> ans;
TreeNode* findNode(TreeNode* root, int key) { // Find the node containing key

    while(root != NULL) {

        if(root->val == key) {
            return root;
        }
        else if(root->val > key) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return NULL;
}

void inorderPred(TreeNode* root, int key){
    // Step 1- Go Left Once
    // Step 2- Then keep Going Right.
    if(root == NULL || root->left == NULL){
        ans.push_back(NULL);
        return;
    }
    
    TreeNode* pred = root->left;
    while(pred->right != NULL){ // keep going right
        pred = pred->right;
    }
    ans.push_back(pred);
    return;
}

void inorderSucc(TreeNode* root, int key){
    // Step 1- Go Right Once
    // Step 2- Keep Going Left
    if(root == NULL || root->right == NULL){
        ans.push_back(NULL);
        return;
    }

    TreeNode* succ = root->right;
    while(succ->left != NULL){
        succ = succ->left;
    } 
    ans.push_back(succ);
    return;
}

int main(){
    
    // [10,5,2,4,3,8,20,15,12,13,25] -> Preorder
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);

    root->left->left->right = new TreeNode(4); 
    root->left->left->right->left = new TreeNode(3); 

    root->right->left = new TreeNode(15);
    root->right->left->left = new TreeNode(12);
    root->right->left->left->right = new TreeNode(13);

    root->right->right = new TreeNode(25);

    int key = 5;
    TreeNode* keyNode = findNode(root, key); //Find the node containing key

    if(keyNode == NULL){
        cout << "Key not found";
        return 0;
    }

    inorderPred(keyNode, key);
    inorderSucc(keyNode, key);

    cout << "Predecessor: ";
    if(ans[0] != NULL) cout << ans[0]->val;
    else cout << "NULL";

    cout << endl;

    cout << "Successor: ";
    if(ans[1] != NULL) cout << ans[1]->val;
    else cout << "NULL";
}

//Leetcode 450. Delete Node in a BST
class Solution {
public:
    TreeNode* inop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right != NULL){
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return NULL;
        if(root->val == key){
            // Case 1: Leaf Node
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }

            // Case 2: 1 Child Node
            else if(root->left == NULL || root->right == NULL){
                if(root->left != NULL)return root->left;
                else return root->right;
            }

            // Case 3: 2 Child Node
            else{ 
                // Replace the root Node with it's inorder predecessor / successor
                TreeNode* pred = inop(root);
                root->val = pred->val;
                root->left = deleteNode(root->left,pred->val);
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};