class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();  // Total number of elements in the array
        int count = 0;        // Stores the length of the longest subarray (after deleting one element)
        int zeroes = 0;       // To count the number of 0s in the current window
        int left = 0;         // Left pointer of the sliding window

        // Traverse the array using a sliding window
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroes++;  // Found a 0 in the current window
            }

            // If more than 1 zero, shrink the window from the left
            while (zeroes > 1) {
                if (nums[left] == 0) {
                    zeroes--;  // Decrease zero count when moving past a 0
                }
                left++;  // Move the left boundary to the right
            }

            // Calculate the length of the current valid window (excluding one element)
            // We subtract left from i (right pointer) to get the length
            // This works because we are allowed to delete exactly one element
            count = max(count, i - left);
        }

        return count;  // Return the maximum length found
    }
};
