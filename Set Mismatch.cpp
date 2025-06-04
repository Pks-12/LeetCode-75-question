class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array (should be n numbers from 1 to n)

        int duplicate = -1, missing = -1; // Initialize variables to store the duplicate and missing numbers

        vector<int> count(n + 1, 0); // Create a count array of size n+1 (index 0 unused)

        // Count how many times each number appears in nums
        for (int i = 0; i < n; i++) {
            count[nums[i]]++; // Increase count for the current number
        }

        // Check which number appears twice and which is missing
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) {
                duplicate = i; // Number that appears twice
            } else if (count[i] == 0) {
                missing = i; // Number that is missing
            }
        }

        // Return the result as a vector: [duplicate, missing]
        return {duplicate, missing};
    }
};
