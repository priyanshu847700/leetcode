/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int search(vector<int>& inorder ,int left,int right,int val){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder , int& idx, int left,int right){
        if(left>right){
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;

        int nextnode_idx=search(inorder,left ,right,root->val);
        root->left=helper(preorder,inorder,idx,left,nextnode_idx-1);
        root->right=helper(preorder,inorder,idx,nextnode_idx+1,right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;

        return helper(preorder,inorder,idx,0,inorder.size()-1);
    }
};