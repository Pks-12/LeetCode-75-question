class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();  // Get the number of rows in the matrix (it's an n x n matrix).

        vector<int> results;  // Create a 1D vector to store all the matrix elements.

        for (int i = 0; i < n; i++) {  // Loop through each row
            for (int j = 0; j < n; j++) {  // Loop through each column in the current row
                results.push_back(matrix[i][j]);  // Add the matrix element to the results vector.
            }
        }

        sort(results.begin(), results.end());  // Sort all the collected elements in ascending order.

        return results[k - 1];  // Return the k-th smallest element (0-based index, so use k-1).
    }
};
