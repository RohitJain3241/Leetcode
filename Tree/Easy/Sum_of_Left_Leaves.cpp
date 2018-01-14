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
private:
    int f(TreeNode* root,bool left){
        if(!root) return 0;
        if(!root->left && !root->right){
            if(left) return root->val;
            else return 0;
        }
        return f(root->left,true) + f(root->right,false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        //Check if it is a left leaf
        return f(root->left,true) + f(root->right,false);
    }
};