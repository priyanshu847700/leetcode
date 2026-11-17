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
    void get_min_diff(TreeNode* root,TreeNode* &prev,int &min_diff){
        if(root == NULL){
            return ;
        }

        get_min_diff(root->left,prev,min_diff);
        if(prev != NULL){
            min_diff=min( abs(root->val - prev->val),min_diff );
        }
        prev = root;
        get_min_diff(root->right,prev,min_diff);

    }
    int getMinimumDifference(TreeNode* root) {
        
        int min_diff=INT_MAX;
        TreeNode *prev=NULL;

        get_min_diff(root,prev,min_diff);

        return min_diff;
    }
};