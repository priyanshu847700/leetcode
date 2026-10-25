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
    TreeNode* add(TreeNode* root, int val, int depth, int currdepth){
        if(root == NULL){
            return NULL;
        }

        if(currdepth == depth-1){
            TreeNode *leftsubtree = root->left;
            TreeNode *rightsubtree = root->right;

            root->left =  new TreeNode(val);
            root->right =  new TreeNode(val);

            root->left->left = leftsubtree;
            root->right->right = rightsubtree;

        }

        root->left=add(root->left,val,depth,currdepth+1);
        root->right=add(root->right,val,depth,currdepth+1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1){
            TreeNode* newroot= new TreeNode(val);
            newroot->left=root;

            return newroot;  
        }

        int currdepth=1;

        return add(root,val,depth,currdepth);
    }
};