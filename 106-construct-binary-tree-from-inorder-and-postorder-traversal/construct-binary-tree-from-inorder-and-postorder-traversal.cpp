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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map <int , int > inMap ;
        for (int i = 0 ;  i < inorder.size() ; i++){ 
            inMap[inorder[i]] = i ;
        }
        TreeNode * root = treebuild (inorder, 0 , inorder.size() - 1 , postorder , 0 , postorder.size() - 1  , inMap ); 
        return  root ;
    }
    TreeNode * treebuild (vector<int>& inorder, int inStart ,int inEnd , vector<int>& postorder , int postStart , int postEnd , map <int , int > &inMap ) {

         if (postStart > postEnd ||  inStart > inEnd ){   //   
            return NULL ;
        }
        TreeNode * root = new TreeNode (postorder[postEnd]) ;
        int inroot = inMap[root->val]  ;

        // int gapright = inEnd - inroot ;
        int gapleft = inroot - inStart  ;

        root ->left = treebuild (inorder , inStart , inroot-1 , postorder , postStart , postStart + gapleft -1  , inMap ) ;
        root ->right = treebuild (inorder , inroot + 1 , inEnd , postorder , postStart+ gapleft  , postEnd -1 , inMap ) ;
        
        return root ;
    }
};