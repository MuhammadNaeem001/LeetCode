class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(TreeNode* node, int remaining) {
        if (!node) return;
        path.push_back(node->val);
        remaining -= node->val;
        if (!node->left && !node->right && remaining == 0) {
            result.push_back(path);
        } else {
            dfs(node->left, remaining);
            dfs(node->right, remaining);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }
};
