class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element is less than the next one → go right
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            // Else peak is in left side or mid is itself
            else {
                right = mid;
            }
        }

        return left; // left == right --> peak index
    }
};
