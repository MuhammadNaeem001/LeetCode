class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // Case 1: dono null
        if (!p && !q) return true;

        // Case 2: ek null ek non-null
        if (!p || !q) return false;

        // Case 3: values different
        if (p->val != q->val) return false;

        // Recursively left & right subtrees check karo
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
