class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;  // This will store all rows of Pascal's triangle
        
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1); // Each row has (i+1) elements, initialized with 1
            
            // Fill the middle elements (not first or last)
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j]; 
            }
            
            ans.push_back(row); // Add the completed row to the result
        }
        
        return ans;
    }
};
