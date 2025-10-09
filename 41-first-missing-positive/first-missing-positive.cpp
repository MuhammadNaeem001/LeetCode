class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace invalid numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2: Mark presence by negating index
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num >= 1 && num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        // Step 3: Find first positive index
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }

        // Step 4: All present
        return n + 1;
    }
};
