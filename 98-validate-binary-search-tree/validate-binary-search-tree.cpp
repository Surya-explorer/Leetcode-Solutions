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
    bool solve (TreeNode* &root , long int_min , long int_max){
        if (root == NULL) return true ;
        // if (root ->left && root ->right ){
        // if (root->left->val >=root->val || root->right->val <=root->val) return false ;
        if (root->val >= int_max || root->val <= int_min) return false ;
        // }
        return solve (root ->left , int_min , root->val ) && solve (root ->right , root ->val , int_max ) ;
    }
    bool isValidBST(TreeNode* root) {
        return solve (root , LONG_MIN , LONG_MAX) ;
    }
};