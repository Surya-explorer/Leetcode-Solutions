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

    pair<bool , int> solve(TreeNode* root){
        if (root == NULL) {
            pair<bool , int > p = make_pair(true , 0 ) ;
            return p ;
        }
        pair< bool , int > left = solve(root->left) ;
        pair< bool , int > right = solve(root->right) ;
        bool left_ans = left.first;
        bool right_ans = right.first ;
        bool diff = abs(left.second - right.second) <= 1 ;
        pair <bool , int> ans ;
        if(left_ans && right_ans && diff)  ans.first = true ;
        else ans.first = false ;
        ans.second = max(left.second, right.second) + 1;

        return ans ;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).first; 
    }
};