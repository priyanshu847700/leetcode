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
    pair<int,int> solve(TreeNode* root,int &res){
        if(root == NULL){
            return {0,0};
        }

        auto p1=solve(root->left,res);
        auto p2=solve(root->right,res);

        int total_sum = p1.first + p2.first + root->val;
        int total_count = p1.second + p2.second + 1;

        int avg = total_sum/total_count;

        if(avg == root->val){
            res++;
        }

        return {total_sum,total_count};
    }
    int averageOfSubtree(TreeNode* root) {
        
        int res=0;

        solve(root,res);
        return res;
    }
};