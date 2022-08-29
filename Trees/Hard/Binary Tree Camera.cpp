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
    int ans;
    set<TreeNode*>covered;
    void solve(TreeNode* root,TreeNode* parent)
    {
        if(root==NULL)
            return;
        solve(root->left,root);
        solve(root->right,root);
        if(parent==NULL and covered.find(root)==covered.end() or covered.find(root->left)==covered.end()
          or covered.find(root->right)==covered.end())
        {
            ans++;
            covered.insert(root);
            covered.insert(parent);
            covered.insert(root->left);
            covered.insert(root->right);
        }
    }
    int minCameraCover(TreeNode* root) {
       ans=0;
        covered.insert(NULL); // Skip the leaf nodes and start from one level above.
        solve(root,NULL);
        return ans;
    }
};