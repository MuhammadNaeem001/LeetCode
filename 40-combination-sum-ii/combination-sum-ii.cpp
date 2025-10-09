class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break; // no need to continue further

            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backtrack(candidates, target, 0, curr);
        return res;
    }
};
