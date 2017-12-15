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
    //global vector of strings
    vector<string> result;
    void f(TreeNode* root,string a){
        a = a + "->" + to_string(root->val); 
        //If it is a leaf node we will simply add 'a' to result and return
        if(root->left==NULL && root->right==NULL){
            //This is for removing the first arrow sign
            a.erase(0,2);
            result.push_back(a);
            return;
        }
        //else if left is null do for right
        if(root->left==NULL){
            f(root->right,a);
            return;
        }
        //else if right is null do for left
        if(root->right==NULL){
            f(root->left,a);
            return;
        }
        //If both are not null then do it for both the subtrees
        f(root->left,a); f(root->right,a);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        //This is for handling the null case
        if(root==NULL)
            return result;
        //Whenever we reach at the leaf node we will push the string into 'result'
        string a;
        //Here string a will keep the present status of the path
        f(root,a);
        return result;
    }
};