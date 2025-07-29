class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array

        // Create a result array of same size, initialized with 0
        vector<int> results(n, 0);

        // These variables will help us place positive and negative numbers alternatively
        int positiveIndex = 0; // Start placing positive numbers at even indices
        int negativeIndex = 1; // Start placing negative numbers at odd indices

        // Loop through the original array
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                // Place negative number at the current negativeIndex
                results[negativeIndex] = nums[i];
                negativeIndex += 2; // Move to next odd index
            } else {
                // Place positive number at the current positiveIndex
                results[positiveIndex] = nums[i];
                positiveIndex += 2; // Move to next even index
            }
        }

        // Return the rearranged array
        return results;
    }
};
