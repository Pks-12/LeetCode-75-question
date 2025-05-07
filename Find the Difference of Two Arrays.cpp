class Solution {
public:
    bool isPresent(vector<int>& nums, int value) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == value) {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> onlyInNums1;
        vector<int> onlyInNums2;

        int m = nums1.size();
        int p = nums2.size();

        // Elements in nums1 but not in nums2
        for (int i = 0; i < m; i++) {
            if (!isPresent(nums2, nums1[i]) && !isPresent(onlyInNums1, nums1[i])) {
                onlyInNums1.push_back(nums1[i]);
            }
        }

        // Elements in nums2 but not in nums1
        for (int i = 0; i < p; i++) {
            if (!isPresent(nums1, nums2[i]) && !isPresent(onlyInNums2, nums2[i])) {
                onlyInNums2.push_back(nums2[i]);
            }
        }

        return {onlyInNums1, onlyInNums2};
    }
};
