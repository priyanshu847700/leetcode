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
    void solve(TreeNode* root, int targetSum, int &count,long long sum){
        if(root == NULL){
            return;
        }

        sum+=root->val;
        if(sum == targetSum){
            count++;
        }

        solve(root->left,targetSum,count,sum);
        solve(root->right,targetSum,count,sum);

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        
        int count=0;
        solve(root,targetSum,count,0);
        
        count+= pathSum(root->left,targetSum);
        count+= pathSum(root->right,targetSum);

        return count;
    }
};