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
    TreeNode *maketree(vector<int>& inorder, int start1, int end1 ,vector<int>& postorder, int start2 ,int end2){ 
        if(end1<start1)
            return NULL;
        //First we make the last element of the postorder as the root of this tree
        TreeNode *root = new TreeNode( postorder[end2] );
        //We find this element in the inorder array
        int index;
        for(int i=start1;i<=end1;i++){
            if(postorder[end2]==inorder[i]){
                index = i;
                break;
            }
        }
        
        //Now we construct the left and right subtree
        root->left = maketree(inorder,start1,index-1,postorder,start2,start2+index-start1-1);
        root->right = maketree(inorder,index+1,end1,postorder,start2+index-start1,end2-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n==0)
            return NULL;
        return maketree(inorder,0,n-1,postorder,0,n-1);
    }
};