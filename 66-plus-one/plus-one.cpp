class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from last digit to first
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;     // just increment and return
                return digits;
            }
            digits[i] = 0;       // if 9, make it 0 and continue
        }

        // If all digits were 9, we need an extra 1 at front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
