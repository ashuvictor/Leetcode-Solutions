

iven the root of a binary tree, return the leftmost value in the last row of the tree.
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
    int ans;int lowest=-1;
    void solve(TreeNode* root,int level){
        if(root==NULL)
            return;
        if(level>lowest)
        {
            lowest=level;
            ans=root->val;
        }
        solve(root->left,level+1);
       solve(root->right,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return -1;
        ans=0;
        solve(root,0);
        return ans;
            
    }
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return -1;
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            ans=curr->val;
            if(curr->right)
                q.push(curr->right);
            if(curr->left)
                q.push(curr->left);
        }
        return ans;
    }
};