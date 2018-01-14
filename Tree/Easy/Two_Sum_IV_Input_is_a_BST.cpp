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
    vector<int> ele;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        ele.push_back(root->val);
        inorder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        //Converting into an array first
        inorder(root);
        //Now we traverse in both directions
        int start=0,end=ele.size()-1;
        if(start>=end)
            return false;
        while(start<end){
            int temp = ele[start] + ele[end];
            if(temp==k)
                return true;
            else if(temp<k)
                start++;
            else end--;
        }
        return false;
    }
};