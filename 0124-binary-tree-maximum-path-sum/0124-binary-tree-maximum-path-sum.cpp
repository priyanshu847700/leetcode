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
    int solve(TreeNode* root ,int &max_sum){
        if(root == NULL){
            return 0;
        }

        int left = solve(root->left,max_sum);
        int right = solve(root->right,max_sum);

        int neeche_hi_milgaya_ans= left + right + root->val; //1

        int koi_ek_acha=max(left,right)+root->val;        //2

        int only_root_acha=root->val;         //3

        max_sum=max({max_sum,neeche_hi_milgaya_ans,koi_ek_acha,only_root_acha});

        return max(koi_ek_acha,only_root_acha);
    }
    int maxPathSum(TreeNode* root) {
        int max_sum=INT_MIN;

        solve(root,max_sum);

        return max_sum;
    }
};