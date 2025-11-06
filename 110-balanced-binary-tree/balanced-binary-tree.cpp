class Solution {
public:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        int lh = checkHeight(node->left);
        if (lh < 0) return -1;
        int rh = checkHeight(node->right);
        if (rh < 0) return -1;
        if (abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) >= 0;
    }
};
