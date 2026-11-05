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
    void reverse(vector<vector<int>> &ans){
        int i=0;
        int j=ans.size()-1;

        while(i<j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root == NULL) return ans;

        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int> temp;

            while(n--){
                TreeNode* top=q.front();
                q.pop();
                
                temp.push_back(top->val);

                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
            }
            ans.push_back(temp);
    
        }

        reverse(ans);
        return ans;
    }
};