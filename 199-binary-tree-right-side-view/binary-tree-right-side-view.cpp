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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;  // if tree is empty

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int rightmost;  // will store the last node’s value of the current level
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                rightmost = node->val; // keep updating until last node of this level

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(rightmost); // only rightmost visible from this level
        }

        return result;
    }
};
