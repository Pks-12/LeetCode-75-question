class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();  // Step 1: Get the size of the input array

        sort(arr.begin(), arr.end());  // Step 2: Sort the array in ascending order

        vector<vector<int>> result;  // Step 3: Create a 2D vector to store the result pairs

        int a = INT_MAX;  // Step 4: Initialize 'a' to store the minimum difference found
        int difference = 0;  // To store the difference between two adjacent elements

        // Step 5: First pass to find the minimum absolute difference between adjacent elements
        for(int i = 1; i < n; i++) {
            difference = arr[i] - arr[i - 1];  // Difference between current and previous element
            a = min(a, difference);  // Update 'a' if a smaller difference is found
        }

        // Step 6: Second pass to collect all pairs with the minimum difference
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] == a) {  // If the pair has the minimum difference
                result.push_back({arr[i - 1], arr[i]});  // Add the pair to the result
            }
        }

        return result;  // Step 7: Return the result containing all such pairs
    }
};
