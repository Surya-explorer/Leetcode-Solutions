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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int >> ans ;
        if (root == NULL ) return ans ;

        queue <pair <TreeNode* , int >>  q ;
        q.push({root , 0l}) ;
        while (!q.empty()){
            TreeNode * front = q.front().first  ;
            int l = q.front().second  ;
            q.pop() ;
            if (front->left ) {
                TreeNode* left = front->left ;
                q.push({left , l+1}) ;
            }
            if (front->right ) {
                TreeNode* right = front->right  ;
                 q.push({right , l+1}) ;
            }
            if (ans.size() == l) {
                ans.push_back({});
            }
            ans[l].push_back(front->val) ;
        }
        return ans ; 
    }
};