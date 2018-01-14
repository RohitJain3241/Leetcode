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
    int summer=0;
    //This wil return the sum of all lower values
    int f(TreeNode* root){
        if(!root) return 0;
        int l = f(root->left),r = f(root->right);
        summer += abs(l-r);
        return l + root->val + r;
    }
public:
    int findTilt(TreeNode* root) {
        f(root);
        return summer;
    }
};