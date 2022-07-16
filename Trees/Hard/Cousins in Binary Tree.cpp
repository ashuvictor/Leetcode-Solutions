
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.



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
    int xp,yp,xl,yl;
    void solve(TreeNode* root,int x,int y,int p,int l){
        if(root==NULL)
        {
            return;
        }
        if(root->val==x)
        {
            xp=p;xl=l;return;
        }
        if(root->val==y){
            yp=p;
            yl=l;return;
        }
        solve(root->left,x,y,root->val,l+1);
        solve(root->right,x,y,root->val,l+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
         solve(root,x,y,0,0);
        if(xl==yl and xp!=yp)
            return true;
        return false;
    }
};