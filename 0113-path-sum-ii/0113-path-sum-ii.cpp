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
    void get_pathsum(TreeNode* root,int targetSum,int sum,vector<int> &temp,vector<vector<int>> &res){
        if(root == NULL){
            return;
        }

        sum+=root->val;
        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(targetSum == sum){
                res.push_back(temp);
            }
        }

        get_pathsum(root->left,targetSum,sum,temp,res);
        get_pathsum(root->right,targetSum,sum,temp,res);

        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int> temp;
        vector<vector<int>> res;

        get_pathsum(root,targetSum,sum,temp,res);

        return res;
    }
};