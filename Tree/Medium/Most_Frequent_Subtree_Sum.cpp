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
    //This will keep the elements and 2nd will keep the counts
    unordered_map<int,int> counts;
    int maxi=-1;
    int f(TreeNode* root){
        if(!root) return 0;
        int temp = root->val + f(root->left) + f(root->right);
        ++counts[temp];  //This adds that element to the u_map and makes its count as 1 OR counts[temp]++
        if(maxi<counts[temp]) maxi = counts[temp];
        return temp;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        f(root);
        for(const auto& x: counts)
            if(x.second==maxi) res.push_back(x.first);
        return res;
    }
};