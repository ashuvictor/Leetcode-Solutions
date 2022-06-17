
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.


class Solution {
public:
    void solve(TreeNode* root,int prev,int &ans)
    {
        if(root==NULL)
            return;
        if(root->val>=prev){
            ans++;
            prev=root->val;
        }
        solve(root->left,prev,ans);
        solve(root->right,prev,ans);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        solve(root,INT_MIN,ans);
        return ans;    }
};