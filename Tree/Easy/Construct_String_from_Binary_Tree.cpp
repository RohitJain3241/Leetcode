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
public:
    string tree2str(TreeNode* t) {
        if(!t) return "";
        string temp = to_string(t->val);
        if(!t->left && !t->right)
            return temp;
        if(!t->left)
            temp += "()";
        else
            temp += "(" + tree2str(t->left) + ")";
        if(t->right)
            temp += "(" + tree2str(t->right) + ")";
        return temp;
    }
};