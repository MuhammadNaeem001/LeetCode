class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int r = 0;         // start at first row
        int c = cols - 1;  // last column (top-right)

        while (r < rows && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            else if (matrix[r][c] > target) {
                c--;  // too big → go left
            }
            else {
                r++;  // too small → go down
            }
        }

        return false;
    }
};
