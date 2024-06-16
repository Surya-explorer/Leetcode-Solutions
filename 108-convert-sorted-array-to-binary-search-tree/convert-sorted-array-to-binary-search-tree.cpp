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
    // void solve (vector <int> nums , TreeNode * &root , int mid , int i ){
    //     if ( i == mid || i == nums.size()) return ;
        
    //     TreeNode * node = new TreeNode (nums[i]) ;
    //     root->left = node ;
    //     solve (nums , root->left , mid , i+ 1) ;
        
    //     TreeNode * node1 = new TreeNode (nums[i]) ;
    //     root->right = node1  ;
    //     solve (nums , root->left , mid , i+ 1) ;
    // }
    TreeNode * build_BST (vector<int>& nums , int s , int e){
        
        if (s > e) return NULL ;
        int mid =  (s + e)/2  ;
        TreeNode * root = new TreeNode(nums[mid]) ;
        root ->left = build_BST (nums , s , mid- 1) ;
        root ->right = build_BST (nums , mid+ 1 , e) ;

        return root ;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_BST (nums , 0 , nums.size() - 1  ) ;
    }
};