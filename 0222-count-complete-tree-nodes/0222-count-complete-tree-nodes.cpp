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
    int get_left_nodes(TreeNode* root){
        int count=0;
        TreeNode* temp=root;

        while(temp != NULL){
            count++;
            temp=temp->left;
        }
        return count;
    }

    int get_right_nodes(TreeNode* root){
        int count=0;
        TreeNode* temp=root;

        while(temp != NULL){
            count++;
            temp=temp->right;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int left=get_left_nodes(root);
        int right=get_right_nodes(root);

        if(left == right){
            return pow(2,left) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};