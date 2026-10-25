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
    void calculate_diff(TreeNode* root,TreeNode* child,int &diff){
        if(child == NULL){
            return;
        }

        diff= max(diff,abs(root->val - child->val));

        calculate_diff(root,child->left,diff);
        calculate_diff(root,child->right,diff);
    }
    void max_diff(TreeNode* root,int &diff){

        if(root == NULL){
            return;
        }

        calculate_diff(root,root->left,diff);
        calculate_diff(root,root->right,diff);

        max_diff(root->left,diff);
        max_diff(root->right,diff);

    }
    
    int maxAncestorDiff(TreeNode* root) {
        int diff=0;

        max_diff(root,diff);

        return diff;
    }
};