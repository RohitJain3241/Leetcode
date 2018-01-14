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
    vector<int> v;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        //Doing the inorder traversal and returning the answer
        inorder(root);
        sort(v.begin(),v.end());
        if(v[v.size()-1]==v[0]) return -1;
        int res = v[upper_bound(v.begin(),v.end(),root->val)-v.begin()];
        //cout << res << endl;
        //if(res==root->val) return -1;
        return res;
    }
};