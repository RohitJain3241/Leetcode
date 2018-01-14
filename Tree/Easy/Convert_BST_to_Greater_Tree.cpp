/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int summer=0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        //We will traverse the tree in postorder format
        //We will maintain a running sum too
        convertBST(root->right);
        root->val += summer; summer = root->val;
        convertBST(root->left);
        return root;
    }
};