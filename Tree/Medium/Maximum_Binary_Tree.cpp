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
    TreeNode* createtree(vector<int>& nums,int start,int end){
        if(start>end)
            return NULL;
        //This part is for finding the max.
        //Creating the root firstly
        int maxi = -1234234,idx;
        for(int i=start;i<=end;i++){
            if(maxi<nums[i]){
                maxi = nums[i]; idx = i;
            }
        }
        TreeNode* root = new TreeNode(nums[idx]); 
        root->left = createtree(nums,start,idx-1);
        root->right = createtree(nums,idx+1,end);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return createtree(nums,0,n-1);
    }
};