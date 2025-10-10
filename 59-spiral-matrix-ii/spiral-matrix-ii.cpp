class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1, total = n * n;

        while (num <= total) {
            // Left → Right
            for (int i = left; i <= right && num <= total; i++)
                matrix[top][i] = num++;
            top++;

            // Top → Bottom
            for (int i = top; i <= bottom && num <= total; i++)
                matrix[i][right] = num++;
            right--;

            // Right → Left
            for (int i = right; i >= left && num <= total; i--)
                matrix[bottom][i] = num++;
            bottom--;

            // Bottom → Top
            for (int i = bottom; i >= top && num <= total; i--)
                matrix[i][left] = num++;
            left++;
        }

        return matrix;
    }
};
