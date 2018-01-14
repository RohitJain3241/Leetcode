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
    //This checks if both root1 and root2 are symmetric to each other
    bool symmetry(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL)
            return true;
        if(root1==NULL && root2!=NULL)
            return false;
        if(root1!=NULL && root2==NULL)
            return false;
        if(root1->val!=root2->val)
            return false;
        return symmetry(root1->left,root2->right) && symmetry(root1->right,root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return symmetry(root->left,root->right);
    }
};