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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int level=1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();

            while(n--){
                TreeNode* curr=q.front();
                q.pop();


                if(level == depth-1){
                    TreeNode* leftsubtree=curr->left;
                    TreeNode* rightsubtree=curr->right;

                    curr->left= new TreeNode(val);
                    curr->right= new TreeNode(val);

                    curr->left->left=leftsubtree;
                    curr->right->right=rightsubtree;
                }
                else{
                    if(curr->left != NULL) q.push(curr->left);
                    if(curr->right != NULL) q.push(curr->right);
                }
            }

            if(level == depth - 1) break; 
            level++;
            
        }

        return root;
    }
};