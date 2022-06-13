

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(root==NULL)
            return ans;
      
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
           double sum=0;
            for(int i=0;i<sz;i++){
                TreeNode* temp;
                temp=q.front();
                q.pop();
                sum+=temp->val;
              
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
          
            double avg=sum/sz;
            ans.push_back(avg);
        }
        return ans;
            
    }
};