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
        
         map<int, int> inMap;
        
        // Populate the map with indices
        // of elements in the inorder traversal
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        
        // Call the private helper function
        // to recursively build the tree
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        
        return root;
    }

private:
    // Recursive helper function to build the tree
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
            vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
                // Base case: If the start indices 
                // exceed the end indices, return NULL
                if(preStart > preEnd || inStart > inEnd){
                    return NULL;
                }
                
                // Create a new TreeNode with value
                // at the current preorder index
                TreeNode* root = new TreeNode(preorder[preStart]);
                
                // Find the index of the current root
                // value in the inorder traversal
                int inRoot = inMap[root->val];
                
                // Calculate the number of
                // elements in the left subtree
                int numsLeft = inRoot - inStart;
                
                // Recursively build the left subtree
                root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, 
                                inorder, inStart, inRoot - 1, inMap);
                
                // Recursively build the right subtree
                root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, 
                                inorder, inRoot + 1, inEnd, inMap);
                
                // Return the current root node
                return root;
            }
    //     if(preorder.size() != inorder.size()) return NULL ;
    //     unordered_map <int , int > inMap ;
    //     for (int i = 0 ; i< inorder.size() ; i++ ){
    //         inMap[inorder[i]] = i ;
    //     }
    //     TreeNode * root = inbuild (preorder, 0 , inorder , 0 , inorder.size() -1 , inMap ) ;
    //     return root ;
    // }
    // private : 
    // TreeNode * inbuild (vector<int>& preorder, int prestart , vector<int>& inorder , int instart ,int inend , unordered_map <int , int >inMap ) {

    //     if (prestart > preend ||  instart > inend ){   //   
    //         return NULL ;
    //     }
    //     TreeNode * root = new TreeNode (preorder[prestart]) ;
    //     int inroot = inMap[root->val] ;  
    //     // It will return the index of the element in the inorder vector .
    //     // Before that element all the elements are for left subtree.
    //     // After that element all elements are for right subtree .

    //     int gap = inroot - instart ;
        

    //     root -> left = inbuild (preorder , prestart + 1 , inorder , instart  , inroot- 1 , inMap ) ;
    //     root -> right = inbuild (preorder , prestart + 1 , inorder , inroot + 1 , inend , inMap )  ;

    //     // root -> left = inbuild (preorder , prestart + 1 , prestart + gap , inorder , instart  , inroot- 1 , inMap ) ;
    //     // root -> right = inbuild (preorder , prestart + gap +  1 , preend , inorder ,inroot + 1 , inend , inMap )  ;
    //     return root ;
    // }
};