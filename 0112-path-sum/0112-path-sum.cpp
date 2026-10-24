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
    bool root_to_node(TreeNode* root, int targetSum,int sum){
        if(root == NULL){
            return false;
        }

        sum+=root->val;
        if(root->left == NULL && root->right == NULL){
            if( sum == targetSum ){
                return true;
            }
            return false;
        }

        return root_to_node(root->left, targetSum, sum) || root_to_node(root->right, targetSum, sum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;

        return root_to_node(root,targetSum,sum);
    }
};