class Solution {
public:
    // Helper function to check if we can make at least 'p' non-overlapping adjacent pairs
    // where the difference between elements in a pair is <= 'maxDiff'
    bool canFormPairs(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        int i = 0;

        while (i < nums.size() - 1) {
            // If the adjacent pair has difference <= maxDiff, we select it
            if (abs(nums[i] - nums[i + 1]) <= maxDiff) {
                count++;
                i += 2; // skip the next element to avoid overlapping
            } else {
                i++; // move to next possible pair
            }
        }

        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end()); // Sort to make nearby elements have smaller difference

        int low = 0;
        int high = nums[nums.size() - 1] - nums[0]; // max possible difference
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Try to see if we can form 'p' pairs with max difference of 'mid'
            if (canFormPairs(nums, p, mid)) {
                ans = mid;     // Possible answer found, try smaller
                high = mid - 1;
            } else {
                low = mid + 1; // Need larger difference
            }
        }

        return ans;
    }
};
