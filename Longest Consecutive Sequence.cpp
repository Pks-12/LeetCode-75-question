class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case: if the array is empty, return 0
        if(n == 0){ 
            return 0;
        }

        // Sort the array to bring consecutive numbers together
        sort(nums.begin(), nums.end());

        int count = 1;      // To track current consecutive sequence length
        int longest = 1;    // To track the longest sequence found so far

        for(int i = 1; i < n; i++) {
            // If current number is same as previous, skip it (remove duplicates)
            if(nums[i] == nums[i - 1]) {
                continue;
            }

            // If current number is exactly 1 more than previous, it's consecutive
            else if(nums[i] == nums[i - 1] + 1) {
                count++;  // Extend the current streak
            }

            // If not consecutive, reset the current count
            else {
                longest = max(longest, count);  // Update the longest if needed
                count = 1;  // Restart count from current number
            }
        }

        // Check one last time in case the longest sequence was at the end
        longest = max(longest, count);

        return longest;
    }
};
