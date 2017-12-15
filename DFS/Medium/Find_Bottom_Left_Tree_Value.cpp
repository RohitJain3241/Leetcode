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
    int findBottomLeftValue(TreeNode* root) {
        //Algorithm will be do bfs until 1 node left in queue
        queue<TreeNode*> q;
        //Pushing the root node
        q.push(root);
        struct TreeNode* last;
        while(!q.empty()){
            last = q.front();
            q.pop();
            if(last->right)
                q.push(last->right);
            if(last->left)
                q.push(last->left);
        }
        return last->val;
    }
};