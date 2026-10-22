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
    TreeNode* solve(vector<int> preorder, vector<int> inorder,int st,int end,int &idx){
        if(st>end) return NULL;

        int rootval=preorder[idx];

        int i=st;
        for(i;i<=end;i++){
            if( rootval == inorder[i] ){
                break;
            }
        }
        
        idx++;

        TreeNode* rootnode=new TreeNode(rootval);
        rootnode->left=solve(preorder,inorder,st,i-1,idx);
        rootnode->right=solve(preorder,inorder,i+1,end,idx);

        return rootnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
        int idx=0;

        return solve(preorder,inorder,0,preorder.size()-1,idx);
    }
};