Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        if(root==NULL)
        return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int diameter(Node* root) {
        if(root==NULL)
        return 0;
        int op1=height(root->left)+height(root->right)+1;
        int op2=diameter(root->left);
        int op3=diameter(root->right);
        return max(op1,max(op2,op3));
    }
};

or 
class Solution {
  public:
  int dia;
    // Function to return the diameter of a Binary Tree.
      int height(Node* root){
       if(root==NULL)
       return 0;
       int lh=height(root->left);
       int rh=height(root->right);
       dia=max(dia,lh+rh+1);
       return 1+max(lh,rh);
           
       }
   int diameter(Node* root) {
        // Your code here
         dia=0;
        height(root);
        return dia;
    }
};
class Solution {
public:;
    
    int solve(TreeNode* root, int &ans){
        if(root==NULL)
            return 0;
        int l=solve(root->left, ans);
        int r=solve(root->right, ans);
        int temp=max(l,r)+1;
        ans=max(ans, l+r+1);
        return temp;
    }
        
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=INT_MIN;
        solve(root,ans);
        return ans-1;
    }
};