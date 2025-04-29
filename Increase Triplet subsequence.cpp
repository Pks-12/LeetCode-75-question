class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]<nums[j]&&nums[j]<nums[k]){ This code me TLE
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        int n = nums.size();
        int a = INT_MAX;
        int b = INT_MAX;
        for(int i=0;i<n;i++){
            int numb= nums[i];
             if (numb <= a) {
                a = numb;
            } else if (numb <= b) {
                b = numb;
            } else {
                return true; 
            }
        }
        return false;
    }
};
