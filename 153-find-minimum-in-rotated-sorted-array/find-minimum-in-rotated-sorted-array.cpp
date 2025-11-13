class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // Agar array rotate nahi hui
        if (nums[left] <= nums[right]) return nums[left];

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum right half me hai
                left = mid + 1;
            } else {
                // Minimum left half me hai including mid
                right = mid;
            }
        }

        return nums[left];
    }
};
