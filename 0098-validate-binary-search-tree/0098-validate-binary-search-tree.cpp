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
    TreeNode* prev = NULL;

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;

        // Left
        if (!isValidBST(root->left))
            return false;

        // Current
        if (prev != NULL && root->val <= prev->val)
            return false;

        prev = root;

        // Right
        return isValidBST(root->right);
    }
};