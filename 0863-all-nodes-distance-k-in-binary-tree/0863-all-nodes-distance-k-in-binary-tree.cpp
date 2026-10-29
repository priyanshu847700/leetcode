/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void make_tree_unidirectional(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& parent) {
        if (root == NULL) return;

        if (root->left != NULL) {
            parent[root->left] = root;
        }
        make_tree_unidirectional(root->left, parent);

        if (root->right != NULL) {
            parent[root->right] = root;
        }
        make_tree_unidirectional(root->right, parent);
    }

    void solve(TreeNode* target, int k,vector<int>& res,unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> isvisited;
        isvisited.insert(target);

        int level = 0;

        while (!q.empty()) {
            if (level == k) {
                while (!q.empty()) {
                    res.push_back(q.front()->val);
                    q.pop();
                }
                return;
            }

            int n = q.size();

            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL && isvisited.count(node->left) == 0) {
                    q.push(node->left);
                    isvisited.insert(node->left);
                }

                if (node->right != NULL && isvisited.count(node->right) == 0) {
                    q.push(node->right);
                    isvisited.insert(node->right);
                }

                if (parent.count(node) && isvisited.count(parent[node]) == 0) {
                    q.push(parent[node]);
                    isvisited.insert(parent[node]);
                }
            }

            level++;
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;

        make_tree_unidirectional(root, parent);

        vector<int> res;
        solve(target, k, res, parent);

        return res;
    }
};
