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
        if(preorder.size() != inorder.size()) return nullptr;

        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return inbuild(preorder, preIndex, 0, inorder.size() - 1, inMap);
    }

private:
    TreeNode* inbuild(const vector<int>& preorder, int& preIndex, int inStart, int inEnd, const unordered_map<int, int>& inMap) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = inMap.at(rootVal);
        
        root->left = inbuild(preorder, preIndex, inStart, inRootIndex - 1, inMap);
        root->right = inbuild(preorder, preIndex, inRootIndex + 1, inEnd, inMap);

        return root;
    }
};
