class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;               // To store the number of subarrays with sum = k
        int n = nums.size();         // Length of the input array
        
        // Outer loop: pick the start index of subarray
        for(int start = 0; start < n; start++) {
            int sum = 0;             // Initialize sum for current subarray
            
            // Inner loop: pick the end index of subarray
            for(int end = start; end < n; end++) {
                sum += nums[end];    // Add current element to sum
                
                // Check if the current sum equals the target k
                if(sum == k) {
                    count++;         // Found a valid subarray, increment count
                }
            }
        }
        
        return count;                // Return total count of valid subarrays
    }
};
