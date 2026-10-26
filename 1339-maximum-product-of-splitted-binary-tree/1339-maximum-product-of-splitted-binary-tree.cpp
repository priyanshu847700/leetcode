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
    int total_sum(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftsubtreesum=total_sum(root->left);
        int rightsubtreesum =total_sum(root->right);

        return root->val + leftsubtreesum + rightsubtreesum;
    }

    long long find_max_product(TreeNode* root,long long &max_product,long long sum){
        if(root == NULL){
            return 0;
        }

        long long leftsum = find_max_product(root->left,max_product,sum);
        long long rightsum = find_max_product(root->right,max_product,sum);

        long long sub_sum = root->val + leftsum + rightsum;     //s1
        long long remaining_sum = sum-sub_sum;                  //s2

        max_product=max(max_product,sub_sum * remaining_sum);

        return sub_sum;        
    }

    int maxProduct(TreeNode* root) {

        long long sum=total_sum(root);
        long long max_product=0;

        if(root == NULL){
            return 0;
        }

        find_max_product(root,max_product,sum);

        return max_product%(1000000007);
    }
};