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
    int h(TreeNode* root){
        if(root==NULL)
            return 0;
        else
            return 1+max(h(root->left),h(root->right));
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int height = h(root);
        vector<vector<int> > v(height,vector<int>(0,0));
        if(root==NULL)
            return v;
        //We maintain 2 indices present and future
        //present saves the no. of nodes in present layer
        //future saves the no. of nodes in next layer
        int present=1,future=0,i=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            struct TreeNode* temp = q.front();
            q.pop();
            //reducing 1 from present layer
            present--;
            v[i].push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
                future++;
            }
            if(temp->right){
                q.push(temp->right);
                future++;
            }
            if(present==0){
                //As this is the last node visited in this layer
                i++;
                present = future;
                future = 0;
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};