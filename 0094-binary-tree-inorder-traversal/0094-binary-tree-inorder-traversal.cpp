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
    vector<int> inorderTraversal(TreeNode* root) {
        //Morris traversal

        vector<int> res;

        TreeNode* curr=root;
        while(curr != NULL){

            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* leftchild= curr->left;

                while(leftchild->right != NULL){
                    leftchild=leftchild->right;
                }

                leftchild->right = curr;

                // now break connection btw root & root->left
                TreeNode* temp=curr;

                curr=curr->left;           // assigning new curr
                temp->left = NULL;
            }
        }
        return res;
    }
};