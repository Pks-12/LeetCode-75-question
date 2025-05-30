class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();//  Check the size of array
        sort(nums.begin(),nums.end());//    I sort the array as given into the code.(You first sort the array then use it).
        int index=0;//  Then i initialize the variable with zero.If we donot initialize with zero it take garbage value.
        for(int i=1; i<n; i++){
            index = max(index,nums[i]-nums[i-1]);// compare the current gap between with maximum so far
        }
        if(n<2){//  then i check the condition, if fewer value(2) then return zero
            return 0;
        }
        return index;//     return the maximum gap found.
    }
};
