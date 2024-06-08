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
    int solve (TreeNode * root , int &Max ) {
        if (root == NULL){
            return 0;
        }
        int leftMaxpath  = max(0 , solve(root->left   , Max ))   ;
        int rightMaxpath =  max(0 , solve(root->right  , Max ))   ;
        Max =  max ( Max , leftMaxpath + rightMaxpath + root->val  ) ;
        return max(leftMaxpath , rightMaxpath) + root->val ;
    }
    int maxPathSum(TreeNode* root) {
        int Max = INT_MIN  ;
        solve(root , Max ) ;
        return Max ;
    }
};