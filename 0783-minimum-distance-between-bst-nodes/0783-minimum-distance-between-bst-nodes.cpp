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
    void get_min_diff(TreeNode* root,vector<int> &nodes_val){
        if(root == NULL){
            return;
        }

        nodes_val.push_back(root->val);
        get_min_diff(root->left,nodes_val);
        get_min_diff(root->right,nodes_val);
        
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> nodes_val;

        get_min_diff(root,nodes_val);

        int min_diff=INT_MAX;
        for(int i=0;i<nodes_val.size();i++){
            for(int j=i+1;j<nodes_val.size();j++){
                min_diff=min(min_diff ,abs(nodes_val[i] - nodes_val[j]) );
            }
        }

        return min_diff;
    }
};