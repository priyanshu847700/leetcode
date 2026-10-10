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
    void flatten(TreeNode* root) {
        if(root==NULL){
            return ;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode *temp1=root->right;
        TreeNode *temp2=root->left;

        root->left=NULL;
        root->right=temp2;
        
        TreeNode *curr=root;
        while(curr != NULL && curr->right != NULL){
            curr=curr->right;
        }

        curr->right=temp1;
    }
};