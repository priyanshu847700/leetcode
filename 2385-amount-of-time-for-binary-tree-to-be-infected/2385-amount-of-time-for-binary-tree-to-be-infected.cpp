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
    void make_tree_undirected(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        if(root == NULL){
            return;
        }

        if(root->left != NULL){
            parent[root->left]=root;
        }
        make_tree_undirected(root->left,parent);

        if(root->right != NULL){
            parent[root->right]=root;
        }
        make_tree_undirected(root->right,parent);
    }

    void get_time(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent, int &time){

        queue<TreeNode*> q;
        q.push(root);

        unordered_set<int> visited;
        visited.insert(root->val);

        while(!q.empty()){
            int n=q.size();

            while(n--){

                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL && visited.count(node->left->val) == 0 ){
                    q.push(node->left);
                    visited.insert(node->left->val);
                }

                if(node->right != NULL && visited.count(node->right->val) == 0 ){
                    q.push(node->right);
                    visited.insert(node->right->val);
                }

                if(parent[node] && visited.count(parent[node]->val) == 0 ){
                    q.push(parent[node]);
                    visited.insert(parent[node]->val);
                }
            }
            time++;
        }
    }

    void solve(TreeNode* root, int start,unordered_map<TreeNode*,TreeNode*> &parent,int &time){
        if(root == NULL){
            return;
        }

        if(root->val == start){
            get_time(root,parent,time);   
            return; 
        }

        solve(root->left,start,parent,time);
        solve(root->right,start,parent,time);

    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;

        make_tree_undirected(root,parent);

        int time=0;

        solve(root,start,parent,time);

        return time-1;
    }
};