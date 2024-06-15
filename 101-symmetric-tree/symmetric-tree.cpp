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
    void solve(TreeNode* node1 , TreeNode* node2 , bool &ans ){
        if (!node1 && !node2) {
            return; // Both nodes are NULL, they are symmetric
        }
        if (!node1 || !node2 || node1->val != node2->val) {
            ans = false; // Either one is NULL or values do not match
            return;
        }
        solve(node1->left, node2->right, ans);
        solve(node1->right, node2->left, ans);
    }
    bool isSymmetric(TreeNode* root) {
        bool ans  = true ;
        if (root == NULL){
            return true ;
        }
       
        if (root ->left && root->right) {
            TreeNode* node1 = root ->left ;
            TreeNode* node2 = root ->right ;
            solve(node1 , node2 , ans ) ;
        }
        else {
             if (root ->left == NULL && root ->right == NULL) return true ;
            return false ;
        }
        return ans ;
    }
};