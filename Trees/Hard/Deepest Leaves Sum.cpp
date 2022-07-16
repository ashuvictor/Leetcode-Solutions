




Given the root of a binary tree, return the sum of values of its deepest leaves.


class Solution {
public:
    void solve(TreeNode* root,vector<pair<int,int>>&level,int &maxLevel,int temp)
    {
        if(root==NULL)
            return;
        level.push_back({root->val,temp});
        maxLevel=max(maxLevel,temp);
        solve(root->left,level,maxLevel,temp+1);
        solve(root->right,level,maxLevel,temp+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<pair<int,int>>level;
        int maxLevel;
        solve(root,level,maxLevel,0);
        int sum=0;
        for(int i=0;i<level.size();i++)
        {
            if(level[i].second==maxLevel)
                sum+=level[i].first;
        }
        return sum;
    }
};




class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
      int s=0;
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            s=0;
            while(k--){
                TreeNode* curr=q.front();
                q.pop();
                s+=curr->val;
                if(curr->left)
                   q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return s;
    }
};

