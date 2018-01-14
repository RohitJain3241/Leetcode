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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode*> q; q.push(root);
        long long present=1,future=0,summer=0,counter=0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            summer += temp->val;counter++;
            if((temp->left)){
                q.push(temp->left);
                future++;
            }
            if((temp->right)){
                q.push(temp->right);
                future++;
            }
            q.pop(); present--;
            if(present==0){
                res.push_back(summer*1.0000/counter);
                present = future; future = 0;
                summer = counter = 0;
            }
        }
        return res;
    }
};