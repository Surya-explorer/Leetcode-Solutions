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

    // void solve(TreeNode * root ) {
        
    //     if (root == NULL ) {
    //         return   ;
    //     }

    //     if (root ->left) solve(root->left) ;
    //     if (root ->right ) solve(root->right) ;
        
    //     if  (root ->left) {
    //         TreeNode * rleft = root ->left ;
    //         TreeNode * rright = root ->right ;

    //         root ->left = NULL ;
    //         root ->right = rleft ;
            
    //         TreeNode* current = root->right;
    //         while (current->right) {
    //             current = current->right;
    //         }

    //         Attach the saved right subtree
    //         current->right = rright;
    //     }
         
    // }

    void flatten(TreeNode* root) {
        // if (root == NULL) return ;
        // solve (root)  ;
        // return ;
        // 'curr' to the root of the tree
        TreeNode* curr = root;

        // Iterate until 'curr'
        // becomes NULL
        while (curr) {
            // Check if the current
            // node has a left child
            if (curr->left) {
                // If yes, find the rightmost
                // node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }

                // Connect the rightmost node in
                // the left subtree to the current
               //  node's right child
                pre->right = curr->right;

                // Move the entire left subtree to the
                // right child of the current node
                curr->right = curr->left;

                // Set the left child of
                // the current node to NULL
                curr->left = NULL;
            }

            // Move to the next node
            // on the right side
            curr = curr->right;
        }
    }
};