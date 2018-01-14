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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* head = s.top(); s.pop();
            if(!head->left && !head->right){
                res.push_back(head->val);
                continue;
            }
            TreeNode* temp = new TreeNode(head->val); s.push(temp);
            if(head->right) s.push(head->right);
            if(head->left) s.push(head->left);
        }
        return res;
    }
};