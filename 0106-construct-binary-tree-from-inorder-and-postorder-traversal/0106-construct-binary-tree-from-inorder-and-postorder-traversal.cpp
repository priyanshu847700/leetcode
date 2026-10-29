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
    TreeNode* build_tree(vector<int>& inorder, vector<int>& postorder,int st_inorder,int end_inorder,int st_postorder,int end_postorder){

        if(st_inorder > end_inorder){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[end_postorder]);

        int i=st_inorder;

        for( ;i<=end_inorder;i++){
            if(inorder[i] == root->val){ 
                break;
            }
        }

        int left_sz = i - st_inorder;
        int right_sz = end_inorder - i;

        root->left=build_tree(inorder, postorder, st_inorder, i-1, st_postorder, st_postorder+left_sz-1);
        root->right=build_tree(inorder, postorder, i+1, end_inorder, end_postorder-right_sz, end_postorder-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int st_inorder = 0;
        int end_inoder = inorder.size()-1;
        
        int st_postorder = 0;
        int end_postorder = postorder.size()-1;

        return build_tree(inorder, postorder, st_inorder, end_inoder, st_postorder, end_postorder);

    }
};