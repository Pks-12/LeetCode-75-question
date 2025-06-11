class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
       if(n == 0){// Base case: No house to rob
        return 0;
       }
       else if(n == 1) { // Base case: Only one house, rob it
        return nums[0];
       }

       vector<int>houseIndex(n); // Create a houseIndex array to store the maximum money that can be robbed up to house i
       houseIndex[0] = nums[0];// Robbing the first house is the only option
       houseIndex[1] = max(nums[0],nums[1]);// For the second house, choose the max of first or second house

       for(int i = 2; i<n;i++){// Start filling the houseIndex array from the third house onwards
        houseIndex[i] = max(houseIndex[i-1],houseIndex[i-2]+nums[i]);// Either skip the current house (houseIndex[i-1]) or
            // rob the current house and add to the money from two houses before (houseIndex[i-2] + nums[i])
       }
       return houseIndex[n-1];// The last element of houseIndex array contains the maximum money that can be robbed
    }
};
