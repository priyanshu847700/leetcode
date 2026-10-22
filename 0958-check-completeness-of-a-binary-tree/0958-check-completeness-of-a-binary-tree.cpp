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
    int no_of_nodes(TreeNode* root){
        if(root == NULL) return 0;

        int leftsubtree=no_of_nodes(root->left);
        int rightsubtree=no_of_nodes(root->right);

        return leftsubtree+rightsubtree+1;
    }
    bool dfs(TreeNode* root,int i,int total_nodes){
        if(root == NULL) return true;

        if( i > total_nodes) return false;

        if (dfs(root->left, 2 * i, total_nodes) == false) return false;
        if (dfs(root->right, 2 * i + 1, total_nodes) == false) return false;

        return true;
    }
    
    bool isCompleteTree(TreeNode* root) {
        
        int total_nodes=no_of_nodes(root);

        int i=1;
        return dfs(root,i,total_nodes);
        
    }
};