class Solution {
public:
    int get_max_diameter(TreeNode* root, int &max_diameter) {
        if(root == NULL) {
            return 0;
        }

        int l = get_max_diameter(root->left, max_diameter);
        int r = get_max_diameter(root->right, max_diameter);

        max_diameter = max(max_diameter, l + r);

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;

        get_max_diameter(root, max_diameter);

        return max_diameter;
    }
};