class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
