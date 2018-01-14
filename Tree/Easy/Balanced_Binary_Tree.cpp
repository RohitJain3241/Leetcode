/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//We have approached this problem in step-wise fashion so as to optimize the height finding procedure
//Otherwise it will give TLE because of heavy finding the height of both the subtrees before giving result as false
class Solution{
    pair<bool,int> f(TreeNode* root){
        //If it is NULL then height is 0 and it is balanced.
        if(root==NULL)
            return make_pair(true,0);
        pair<bool,int> temp_l = f(root->left);
        if(temp_l.first!=true)
            return make_pair(false,99999);
        pair<bool,int> temp_r = f(root->right);
        if(temp_r.first!=true)
            return make_pair(false,99999);
        if( abs(temp_l.second - temp_r.second) > 1 )
            return make_pair(false,99999);
        
        return make_pair(true,1 + max( temp_l.second,temp_r.second  ) );
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        //Checking for the balance between left and right and returning a bool value as well as height of the subtree
        return f(root).first;
    }
};