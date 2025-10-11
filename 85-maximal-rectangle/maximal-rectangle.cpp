class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> height(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            // Step 1: Build histogram heights
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }

            // Step 2: Compute largest rectangle area for this histogram
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0); // sentinel for remaining bars
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        heights.pop_back();
        return maxArea;
    }
};
