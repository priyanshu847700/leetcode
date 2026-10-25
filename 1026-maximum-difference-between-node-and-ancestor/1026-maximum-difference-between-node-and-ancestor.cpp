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
    int find_max_diff(TreeNode* root,int minV,int maxV){
        if(root == NULL){
            return abs(minV - maxV);
        }

        minV=min(minV,root->val);
        maxV=max(maxV,root->val);

        int l = find_max_diff(root->left,minV, maxV);
        int r = find_max_diff(root->right,minV, maxV);

        return max(l,r);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return 0;

        int minV=INT_MAX;
        int maxV=INT_MIN;

        return find_max_diff(root,minV,maxV);
    }
};