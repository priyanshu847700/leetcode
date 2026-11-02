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
    void solve(TreeNode* root,int &maxpath,int steps,bool goleft){
        if(root == NULL){
            return;
        }
        
        maxpath=max(maxpath,steps);

        if(goleft == true){
            solve(root->left,maxpath,steps+1,false);
            solve(root->right,maxpath,1,true);
        }
        else{ // goright
            solve(root->right,maxpath,steps+1,true);
            solve(root->left,maxpath,1,false);
        }

    }
    int longestZigZag(TreeNode* root) {
        int maxpath=0;

        solve(root, maxpath,0,true);
        solve(root, maxpath,0,false);

        return maxpath;
    }
};