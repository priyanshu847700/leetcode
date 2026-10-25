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
    void get_leafnode(TreeNode* root,vector<int> &leaf_nodes){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root-> right == NULL){
            leaf_nodes.push_back(root->val);
        }

        get_leafnode(root->left,leaf_nodes);
        get_leafnode(root->right,leaf_nodes);

    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1_leaf_nodes;
        vector<int> t2_leaf_nodes;

        get_leafnode(root1,t1_leaf_nodes);
        get_leafnode(root2,t2_leaf_nodes);

        if(t1_leaf_nodes == t2_leaf_nodes){
            return true;
        }
        
        return false;
    }
};