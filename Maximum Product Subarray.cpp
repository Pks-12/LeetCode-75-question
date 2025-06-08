class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();// Get the size of the array
        int result = nums[0];// Initialize result with the first element (in case the array has only one element)
        // Outer loop: start of subarray
        for(int i=0;i<n;++i){
        int product = 1;// Initialize product for each new subarray starting at i
          for(int j=i;j<n;++j){// Inner loop: end of subarray
            product = product*nums[j];// Multiply the current number to the product
            result = max(result,product);// Update result with the maximum product found so far
          }
        }
        return result;// Return the maximum product of any subarray
    }
};
