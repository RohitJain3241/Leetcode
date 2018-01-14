/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//The solution comes by moving in same manner in both the trees.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        //If either of them is NULL OR root values are not same.
        else if(p == NULL || q == NULL || p->val != q->val)
            return false;
        
        //Both have to be structurally same.
        return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    }
};