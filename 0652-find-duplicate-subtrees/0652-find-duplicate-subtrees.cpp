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
    string solve(TreeNode* root,vector<TreeNode*> &res,unordered_map<string,int> &m){
        if(root == NULL){
            return "N";
        }

        string s= to_string(root->val) + "," + solve(root->left,res,m) + "," + solve(root->right,res,m);

        if(m[s] == 1){
            res.push_back(root);
        }

        m[s]++;

        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;

        unordered_map<string,int> m;

        solve(root,res,m);

        return res;
    }
};
