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
    int get_total_nodes(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = get_total_nodes(root->left);
        int right = get_total_nodes(root->right);

        return 1+left+right;
    }

    int get_subtree_sum(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = get_subtree_sum(root->left);
        int right = get_subtree_sum(root->right);

        return root->val+left+right;
    }

    int averageOfSubtree(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        int count=0;

        int sum = get_subtree_sum(root);
        int total_nodes=get_total_nodes(root);

        int avg=sum/total_nodes;

        if(avg == root->val){
            count++;
        }
        
        int left = averageOfSubtree(root->left);
        int right = averageOfSubtree(root->right);

        return count+left+right;
    }
};