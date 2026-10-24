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
    TreeNode* delete_node(TreeNode* root){
        if(root==NULL){
            return NULL;
        }

        root->left=delete_node(root->left);
        root->right=delete_node(root->right);

        if(root->left == NULL && root->right == NULL && root->val == 0){
            return NULL;
        }
        
        return root;
    } 
    TreeNode* pruneTree(TreeNode* root) {
        return delete_node(root);
    }
};