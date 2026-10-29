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
    void get_level_sum(TreeNode* root,vector<int> &level_sum){
        if(root == NULL){
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            int lvl_sum=0;

            while(n--){
                TreeNode* node = q.front();
                q.pop();

                lvl_sum+= node->val;

                if(node->left != NULL ) q.push(node->left);
                if(node->right != NULL ) q.push(node->right);

            }
            level_sum.push_back(lvl_sum);
        }
    } 
    int maxLevelSum(TreeNode* root) {
        vector<int> level_sum;
        
        get_level_sum(root,level_sum);


        int max_level_sum=level_sum[0];
        int ans_level_idx=0;

        for(int i=0;i<level_sum.size();i++){
            max_level_sum=max(max_level_sum,level_sum[i]);
        }

        for(int i=0;i<level_sum.size();i++){
            if(max_level_sum == level_sum[i]){
                ans_level_idx=i+1;
                break;
            }
        }

        return  ans_level_idx;
    }
};