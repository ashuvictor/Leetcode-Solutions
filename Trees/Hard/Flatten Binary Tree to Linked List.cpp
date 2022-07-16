

The sequence of nodes in the linked list should be the same as that of the preorder traversal of the binary tree.
The linked list nodes are the same binary tree nodes. You are not allowed to create extra nodes.
The right child of a node points to the next node of the linked list whereas the left child points to NULL.



Approach: 

The algorithm steps can be stated as: 

If we observe, we are moving in a reverse postorder way : i.e  right, left, root. 
We take a reference variable (say prev) to store the previous node( initialized to NULL).
Whenever we visit a node, we set the right child to the prev and left child to NULL. 
Next we assign this current node to prev.
We perform the above two operations on all the nodes in the traversal.



class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};
Time Complexity: O(N)

Reason: We are doing a simple preorder traversal.

Space Complexity: O(N)

Reason: Worst case time complexity will be O(N) (in case of skewed tree).


//Approach 2
The algorithm approach can be stated as:

Take a stack and push the root node to it.
Set a while loop till the stack is non-empty.
In every iteration, take the node at the top of the stack( say cur) and pop the stack.
If cur has a right child, push it to the stack.
If cur has a left child, push it to the stack.
Set the right child of cur to node at stack’s top.
Set the left child of cur as NULL.



void flatten(node * root) {
  if (root == NULL) return;
  stack < node * > st;
  st.push(root);
  while (!st.empty()) {
    node * cur = st.top();
    st.pop();

    if (cur -> right != NULL) {
      st.push(cur -> right);
    }
    if (cur -> left != NULL) {
      st.push(cur -> left);
    }
    if (!st.empty()) {
      cur -> right = st.top();
    }
    cur -> left = NULL;
  }

}





The algorithm can be described as:

At a node(say cur) if there exists a left child, we will find the rightmost node in the left subtree(say prev).
We will set prev’s right child to cur’s right child,
We will then set cur’s right child to it’s left child.
We will then move cur to the next node by assigning cur it to its right child
We will stop the execution when cur points to NULL.



class Solution {
  node * prev = NULL;
  public:
   void flatten(node* root) {
        node* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				node* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }



};