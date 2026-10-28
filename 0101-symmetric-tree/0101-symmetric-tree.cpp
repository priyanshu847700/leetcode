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
    bool check_if_symmetric(TreeNode* l,TreeNode* r){
        if(l == NULL && r == NULL){
            return true;
        }

        if(l == NULL || r == NULL){ // left != NULL && right == NULL or vise versa!
            return false;
        }

        if(l->val == r->val && check_if_symmetric(l->right,r->left) && check_if_symmetric(l->left,r->right)){
            return true;
        }

        return false;

    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        return check_if_symmetric(root->left,root->right);
    }
};