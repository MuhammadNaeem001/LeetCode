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
    int maxSum = INT_MIN; // global variable to track max path sum
    
    int findMaxPath(TreeNode* root) {
        if (!root) return 0;

        // calculate max path sum for left and right subtrees
        int left = max(0, findMaxPath(root->left));   // ignore negative paths
        int right = max(0, findMaxPath(root->right));

        // update global max sum (path passing through this node)
        maxSum = max(maxSum, left + right + root->val);

        // return max path that can be extended upward
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        findMaxPath(root);
        return maxSum;
    }
};
