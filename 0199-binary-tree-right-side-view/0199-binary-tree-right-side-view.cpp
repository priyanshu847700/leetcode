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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;

        while(! q.empty()){
            int n=q.size();

            TreeNode* curr=NULL;

            while(n--){
                curr=q.front();
                q.pop();

                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            ans.push_back(curr->val);
        }
        return ans;
    }
};