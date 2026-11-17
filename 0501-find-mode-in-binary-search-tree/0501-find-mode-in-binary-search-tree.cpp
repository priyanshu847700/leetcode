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
    int curr_num=0;
    int curr_freq=0;
    int max_freq=0;
    vector<int> res;

    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }

        dfs(root->left);

        if(root->val == curr_num){
            curr_freq++;
        }
        else{
            curr_num=root->val;
            curr_freq=1;
        }

        if(curr_freq > max_freq){
            res = {};
            max_freq = curr_freq;
        }

        if(curr_freq == max_freq){
            res.push_back(root->val);
        }

        dfs(root->right);

    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);

        return res;
    }
};