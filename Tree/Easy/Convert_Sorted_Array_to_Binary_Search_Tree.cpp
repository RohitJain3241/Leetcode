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
    TreeNode* f(vector<int>& nums,int start,int end){
        int sz = end-start+1;
        if(start>end)
            return NULL;
        int mid = start + sz/2;
        TreeNode* root = new TreeNode( nums[mid] );
        root->left = f(nums,start,mid-1);
        root->right = f(nums,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        int n = nums.size();
        if(n==0)
            return NULL;
        return f(nums,0,n-1);
    }
};