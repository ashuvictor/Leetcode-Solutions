


Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

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
    TreeNode* solve(vector<int>preorder,vector<int>inorder,int p,int s,int e)
    {
        if(p>=preorder.size() or s>e)
            return NULL;
        TreeNode* root=new TreeNode(preorder[p]);
        int ind;
        for(int i=s;i<=e;i++){
            if(inorder[i]==preorder[p])
            {
                ind=i;break;
            }
        }
        root->left=solve(preorder,inorder,p+1,s,ind-1);
        root->right=solve(preorder,inorder,p+ind-s+1,ind+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,0,inorder.size()-1);
    }
};