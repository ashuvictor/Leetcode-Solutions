


Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

 

Example 1:


Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]


void helper(TreeNode* &root,vector<TreeNode*>& ans,map<int,int>& mp)
    {
        if(root==NULL){return;}
        
        helper(root->left,ans,mp);
        helper(root->right,ans,mp);
        
        if(mp[root->val])
        {
            if(root->left)
            {
                if(mp[root->left->val]==0)
                {ans.push_back(root->left);}
            }
                
            if(root->right)
            {
                if(mp[root->right->val]==0)
                {ans.push_back(root->right);}
            }
                
            root=NULL;
            return;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        map<int,int> mp;
        for(int i=0;i<to_delete.size();i++)
        {
            mp[to_delete[i]]=1;
        }
        helper(root,ans,mp);
       if(root) ans.push_back(root);
        return ans;  
    