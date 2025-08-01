class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(); // Get the size of the input array
        set<vector<int>> st; // To store unique quadruples (no duplicates)

        // First loop to fix the first number
        for (int i = 0; i < n; i++) {
            // Second loop to fix the second number
            for (int j = i + 1; j < n; j++) {
                set<long long> hashset; // Hash set to track elements for the 4th number

                // Third loop to find third and fourth numbers
                for (int k = j + 1; k < n; k++) {
                    // Calculate current sum of three fixed elements
                    long long sum = (long long)nums[i] + nums[j] + nums[k];

                    // Compute required 4th number to reach the target
                    long long fourth = (long long)target - sum;

                    // If required 4th number is already in hashset, we found a quadruple
                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth}; // create the quadruple
                        sort(temp.begin(), temp.end()); // sort to handle duplicates
                        st.insert(temp); // insert into set to ensure uniqueness
                    }

                    // Add current number to hashset for future lookups
                    hashset.insert(nums[k]);
                }
            }
        }

        // Convert set to vector and return
        return vector<vector<int>>(st.begin(), st.end());
    }
};
