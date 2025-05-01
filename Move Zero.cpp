class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int id=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[id++]=nums[i];
            }
        }
        while(id<n){
            nums[id++]=0;
        }
        // return nums;
    }
};
