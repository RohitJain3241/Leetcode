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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        //We maintain 2 indices present and future
        //present saves the no. of nodes in present layer
        //future saves the no. of nodes in next laye
        int present=1,future=0;
        queue<Treenode*> q;
        q.push(root);
        while(!q.empty()){
            struct TreeNode* temp = q.front();
            q.pop();
            //reducing 1 from present layer
            present--;
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
                v.push_back(temp->data);
                present = future;
                future = 0;
            }
        }
        return v;
    }
};