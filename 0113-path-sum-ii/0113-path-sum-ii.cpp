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
    void root_to_leaf_sum(TreeNode* root, int target,int sum,vector<int> temp,vector<vector<int>> &res){
        if(root == NULL){
            return;
        }

        temp.push_back(root->val);
        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            if( sum == target){
                res.push_back({temp});
            }
        }
       
        root_to_leaf_sum(root->left,target,sum,temp,res);
        root_to_leaf_sum(root->right,target,sum,temp,res);

        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
        vector<vector<int>> res;
        vector<int> temp;

        int sum=0;

        root_to_leaf_sum(root,target,sum,temp,res);

        return res;
    }
};