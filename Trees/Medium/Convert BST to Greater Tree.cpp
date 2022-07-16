


Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int &ind,vector<int>&inorder)
    {
        if(root==NULL or ind>=inorder.size())
            return;
        solve(root->left,ind,inorder);
        root->val=inorder[ind];
        ind++;
        solve(root->right,ind,inorder);
    }
    void solve1(TreeNode* root,vector<int>&inorder)
    {
        if(root==NULL )
            return;
        solve1(root->left,inorder);
        inorder.push_back(root->val);
        solve1(root->right,inorder);
    }
    TreeNode* convertBST(TreeNode* root) {
    if(root==NULL)
        return root;
        vector<int>inorder;
        solve1(root,inorder);
       int n=inorder.size();
        for(int i=n-2;i>=0;i--)
            inorder[i]+=inorder[i+1];
        int ind=0;
        solve(root,ind,inorder);
       
        return root;
    }
};





class Solution {
public:
    
    int s=0;
    
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        convertBST(root->right);
        s+=root->val;
        root->val=s;
        convertBST(root->left);
        return root;
    }
};