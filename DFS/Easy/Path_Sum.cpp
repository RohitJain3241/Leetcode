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
    bool f(TreeNode* root, int sum){
        if(root->left==NULL && root->right==NULL){
            if(root->val==sum)
                return true;
            return false;
        }
        
        //If left is NULL, we see for right
        else if(root->left==NULL){
            return f(root->right,sum-root->val);
        }
        
        //If right is NULL we see for left
        else if(root->right==NULL){
            return f(root->left,sum-root->val);
        }
        
        //Searching for lessened sum in both left and right
        return f(root->left, sum-root->val) || f(root->right, sum-root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        else
            return f(root,sum);
    }
};