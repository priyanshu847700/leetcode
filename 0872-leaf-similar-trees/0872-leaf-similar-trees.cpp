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
    void get_leafnode_from_t1(TreeNode* root1,vector<int> &t1_leaf_nodes){
        if(root1 == NULL){
            return;
        }

        if(root1->left == NULL && root1-> right == NULL){
            t1_leaf_nodes.push_back(root1->val);
        }

        get_leafnode_from_t1(root1->left,t1_leaf_nodes);
        get_leafnode_from_t1(root1->right,t1_leaf_nodes);

    }
    void get_leafnode_from_t2(TreeNode* root2,vector<int> &t2_leaf_nodes){
        if(root2 == NULL){
            return;
        }

        if(root2->left == NULL && root2-> right == NULL){
            t2_leaf_nodes.push_back(root2->val);
        }

        get_leafnode_from_t1(root2->left,t2_leaf_nodes);
        get_leafnode_from_t1(root2->right,t2_leaf_nodes);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1_leaf_nodes;
        vector<int> t2_leaf_nodes;

        get_leafnode_from_t1(root1,t1_leaf_nodes);
        get_leafnode_from_t2(root2,t2_leaf_nodes);

        if(t1_leaf_nodes == t2_leaf_nodes){
            return true;
        }

        return false;
    }
};