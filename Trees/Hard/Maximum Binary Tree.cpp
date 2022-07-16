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
    int index(vector<int>&nums,int l,int r)
    {
        int ans=-1;int maxa=INT_MIN;
        for(int i=l;i<r;i++){
            if(nums[i]>maxa){
                ans=i;maxa=nums[i];
            }
        }
        return ans;
    }
    TreeNode* solve(vector<int>&nums,int l,int r)
    {
        if(l==r)
            return NULL;
        int idx=index(nums,l,r);
        TreeNode* root=new TreeNode(nums[idx]);
        root->left=solve(nums,l,idx);
        root->right=solve(nums,idx+1,r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size());
    }
};