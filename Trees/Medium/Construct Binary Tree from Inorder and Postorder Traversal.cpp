



Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.





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
    TreeNode* solve(vector<int>postorder,vector<int>inorder,int &ps,int s,int e)
    {
        if(ps<0 or s>e)
            return NULL;
        TreeNode* root=new TreeNode(postorder[ps]);
        int ind;
        for(int i=s;i<=e;i++){
            if(postorder[ps]==inorder[i])
            {
                ind=i;break;
            }
        }
        ps--;
        root->right=solve(postorder,inorder,ps,ind+1,e);
        root->left=solve(postorder,inorder,ps,s,ind-1);
    return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int m=postorder.size()-1;
        return solve(postorder,inorder,m,0,m);
    }
};