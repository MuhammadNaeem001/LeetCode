class Solution {
public:
    void backtrack(int i, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base case: target achieved
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Base case: out of range or target exceeded
        if (i >= candidates.size() || target < 0) return;

        // Choose the current number
        current.push_back(candidates[i]);
        backtrack(i, target - candidates[i], candidates, current, result);
        current.pop_back();

        // Skip the current number and move to next
        backtrack(i + 1, target, candidates, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, target, candidates, current, result);
        return result;
    }
};
