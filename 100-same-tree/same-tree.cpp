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

    bool solve(TreeNode* p, TreeNode* q , bool &ans ) {
        if (!p && !q) {
            return true;
        }
        // If the values of the nodes are different, they are not the same
        if (!p || !q) {
            return  false; 
        } 
        if (p->val != q->val){
            return false ;
        }
        return solve(p-> left , q ->left , ans ) && solve(p->right , q ->right , ans ); 
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {

        bool ans = true  ;
        return solve(p , q , ans) ;
        
    }

};