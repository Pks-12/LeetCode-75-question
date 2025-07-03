class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;

        // Step 1: Calculate the sum of the first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        //  Initialize maxAverage with this initial sum
        double maxAverage = sum;

        //  Step 2: Slide the window from k to end
        for (int i = k; i < n; i++) {
            sum = sum + nums[i] - nums[i - k]; // Slide the window
            maxAverage = max(maxAverage, sum); // Update max if current is better
        }

        //  Return the max average
        return maxAverage / k;
    }
};
