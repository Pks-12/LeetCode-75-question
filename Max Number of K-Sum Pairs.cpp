class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int a=0;
        int l=0;
        int n=nums.size();
        int r=n-1;
        sort(nums.begin(),nums.end());
       while(l<r){
        int sum=nums[l]+nums[r];
            if(sum<k){
                l++;
            }
            else if(sum>k)
            {
                r--;
            }
            else{
                a++;
                l++;
                r--;
            }
        }
            return a;
    }
};
