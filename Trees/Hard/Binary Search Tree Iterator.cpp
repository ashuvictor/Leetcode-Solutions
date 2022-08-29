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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        int data=temp->val;
        temp=temp->right;
        while(temp!=NULL){
         st.push(temp);
            temp=temp->left;
        }
        return data;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};