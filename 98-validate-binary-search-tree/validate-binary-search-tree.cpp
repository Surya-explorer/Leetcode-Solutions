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

    // int solve(TreeNode * root  ){
    //     if (root == NULL || root && !root->left && !root->right) {
    //         return 1 ;
    //     }
    //     if ((root ->left && root->val <= root->left->val) || 
    //         (root->right && root->val >= root->right->val) ) 
    //         return 0 ;
    //     return  solve(root->left ) && solve(root->right ) ;
    // }
    // bool isValidBST(TreeNode* root) {
    //     return solve (root ) ;
    // }
bool isValidBST(TreeNode* root, TreeNode* minNode = NULL, TreeNode* maxNode = NULL) {
    if (root == NULL) return true;
    if ((minNode != NULL && root->val <= minNode->val) || 
       (maxNode != NULL && root->val >= maxNode->val)) {
        return false;
    }
    return isValidBST(root->left, minNode, root) && 
            isValidBST(root->right, root, maxNode);
}

};