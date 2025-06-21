class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();            // Get the size of the input array
        
        sort(nums.begin(), nums.end()); // Sort the array in ascending order
        
        int count = n - k;              // Calculate the index of the k-th largest element in the sorted array
                                       // Since the array is sorted ascending,
                                       // the k-th largest is at index (n - k)
        
        for (int i = 0; i < n; i++) {  // Loop through the sorted array
            if (i == count) {           // When the current index matches the k-th largest index
                return nums[i];         // Return the element at that index
            }
        }
        
        return -1;                     // Return -1 if k is invalid (should not happen if input constraints are followed)
    }
};
