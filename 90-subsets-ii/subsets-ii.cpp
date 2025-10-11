class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        backtrack(0, nums, subset, result);
        return result;
    }

private:
    void backtrack(int start, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;

            subset.push_back(nums[i]);
            backtrack(i + 1, nums, subset, result);
            subset.pop_back();
        }
    }
};
