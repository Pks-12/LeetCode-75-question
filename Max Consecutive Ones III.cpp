class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int maxLength = 0;
        int zeroCount = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroCount++;
            }
            while(zeroCount>k){
                if(nums[left]==0){
                    zeroCount--;
                }
                left++;
            }
            maxLength = max(maxLength,i-left+1);
        }
        return maxLength;
    }
};
