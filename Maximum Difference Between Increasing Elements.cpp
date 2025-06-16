class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array

        if(n <= 1){ 
            return -1;  // If array has 0 or 1 element, no valid pair exists, so return -1
        } 

        int maxDifference = -1;  // Initialize max difference to -1 (default if no positive difference found)
        int difference = 0;      // Variable to store current difference

        // Loop through each element as the first number (nums[i])
        for(int i = 0; i < n; i++){
            // Loop through the elements that come after nums[i]
            for(int j = i + 1; j < n; j++){
                // We only care about pairs where the second number is greater (positive difference)
                if(nums[j] > nums[i]){
                    // Calculate the difference
                    difference = nums[j] - nums[i];

                    // Update the maximum difference if this one is larger
                    maxDifference = max(maxDifference, difference);
                }
            }
        }

        return maxDifference;  // Return the maximum difference found
    }
};
