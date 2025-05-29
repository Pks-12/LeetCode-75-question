class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(); // size check of the array.
        int index; //   declare the variable index.
        for(int i=0;i<n;i++){
            index = abs(nums[i]);// ensure the we get original number. Because the values are being marked as negative to indicate visited.
            if(nums[index]<0){//    Then I checked the condition that the value at index is already negative
                return index;// return the duplicate value found
            }
            nums[index] = -nums[index];//   Mark as visited code completed.
        }
        return -1;//  if no duplicate value found.
    }
};
