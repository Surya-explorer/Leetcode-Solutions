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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
        if(preorder.size() != inorder.size()) return NULL ;
        map <int , int > inMap ;
        for (int i = 0 ; i< inorder.size() ; i++ ){
            inMap[inorder[i]] = i ;
        }
        TreeNode * root = inbuild (preorder, 0 , preorder.size() - 1 , inorder , 0 , inorder.size() -1 , inMap ) ;
        return root ;
    }
    private : 
    TreeNode * inbuild (vector<int>& preorder, int preStart ,int preEnd , vector<int>& inorder , int inStart ,int inEnd ,map <int , int >&inMap ) {

        if (preStart > preEnd ||  inStart > inEnd ){   //   
            return NULL ;
        }
        TreeNode * root = new TreeNode (preorder[preStart]) ;
        int inroot = inMap[root->val] ;  
        // It will return the index of the element in the inorder vector .
        // Before that element all the elements are for left subtree.
        // After that element all elements are for right subtree .


        //////
        int gapleft = inroot - inStart ;
        root -> left = inbuild (preorder , preStart + 1 , preStart + gapleft , inorder , inStart  , inroot- 1 , inMap ) ;
        root -> right = inbuild (preorder ,  preStart + gapleft + 1 , preEnd  ,inorder , inroot + 1 , inEnd , inMap )  ;

        // root -> left = inbuild (preorder , prestart + 1 , prestart + gap , inorder , instart  , inroot- 1 , inMap ) ;
        // root -> right = inbuild (preorder , prestart + gap +  1 , preend , inorder ,inroot + 1 , inend , inMap )  ;
        return root ;
    }
};