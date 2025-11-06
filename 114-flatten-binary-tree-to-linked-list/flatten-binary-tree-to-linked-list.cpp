class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = nullptr;
        root->right = left;

        TreeNode* p = root;
        while (p->right) {
            p = p->right;
        }
        p->right = right;
    }
};
