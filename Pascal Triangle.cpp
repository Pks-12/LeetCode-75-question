class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;  // Final 2D vector to hold the triangle
        
        for(int row = 0; row < numRows; row++) {
            vector<int> ansRow(row + 1, 1); // Start with all 1s
            
            for(int col = 1; col < row; col++) {
                ansRow[col] = ans[row - 1][col - 1] + ans[row - 1][col]; // Pascal's logic
            }

            ans.push_back(ansRow); // Add current row to final answer
        }

        return ans;
    }
};
