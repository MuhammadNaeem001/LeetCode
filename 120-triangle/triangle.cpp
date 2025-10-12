class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Start with the last row
        vector<int> dp(triangle.back());
        
        // Iterate from second-last row up to the top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        
        // The top element contains the minimum path sum
        return dp[0];
    }
};
