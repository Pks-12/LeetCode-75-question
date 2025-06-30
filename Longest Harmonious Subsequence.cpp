class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end()); // Sort array
        int maxLength = 0;
        int i = 0;

        while (i < n) {
            int count = 0;
            int j = i;

            // Count elements with same starting number
            while (j < n && nums[j] == nums[i]) {
                j++;
            }

            // Now count how many nums[j] == nums[i] + 1
            int k = j;
            while (k < n && nums[k] == nums[i] + 1) {
                k++;
            }

            // If we found a valid harmonious subsequence
            if (k > j) {
                maxLength = max(maxLength, (j - i) + (k - j));
            }

            // Move to next group
            i = j;
        }

        return maxLength;
    }
};
