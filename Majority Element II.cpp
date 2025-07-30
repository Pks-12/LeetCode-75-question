class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //  Brute Force apporach
        // vector<int> ls;              // To store the result elements
        // int n = nums.size();

        // for(int i = 0; i < n; i++) {
        //     int count = 0;

        //     // Check if nums[i] is already in the result list
        //     bool alreadyAdded = false;
        //     for(int x : ls) {
        //         if(x == nums[i]) {
        //             alreadyAdded = true;
        //             break;
        //         }
        //     }
        //     if(alreadyAdded) continue;

        //     // Count how many times nums[i] appears
        //     for(int j = 0; j < n; j++) {
        //         if(nums[j] == nums[i]) {
        //             count++;
        //         }
        //     }

        //     // If count > n/3, add to result
        //     if(count > n / 3) {
        //         ls.push_back(nums[i]);
        //     }
        // }

        // return ls;

        vector<int>ls;
        int n = nums.size();
        map<int,int> mpp;
        int mini = n/3;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for (auto it : mpp) {
            if (it.second > mini) {
                ls.push_back(it.first);
            }
        }

        return ls;
    }
};
