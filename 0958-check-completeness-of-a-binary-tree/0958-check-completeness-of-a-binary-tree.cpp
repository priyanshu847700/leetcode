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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool see_null_in_past=false;

        while(!q.empty()){
            int n=q.size();

            while(n--){
                TreeNode* curr=q.front();
                q.pop();

                if(curr == NULL){
                    see_null_in_past=true;
                }
                else{
                    if(see_null_in_past == true){
                        return false;
                    }

                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }

        return true;
    }
};