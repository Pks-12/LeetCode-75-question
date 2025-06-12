class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Sort the array to make divisibility checks easier (i.e., a < b)
        sort(nums.begin(), nums.end());
        
        // result[i] = length of the largest divisible subset ending at index i
        vector<int> result(n, 1);
        
        // previous[i] = index of the previous element in the subset ending at i
        vector<int> previous(n, -1);
        
        // maxIndexes will store the index of the last element of the longest subset
        int maxIndexes = 0;
        
        // Edge case: if input is empty, return an empty vector
        if (n == 0) return {};
        
        // Step 2: Dynamic Programming - build up the solution
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                
                // If nums[i] is divisible by nums[j] and leads to a longer subset
                if (nums[i] % nums[j] == 0 && result[i] < result[j] + 1) {
                    result[i] = result[j] + 1;   // update the length
                    previous[i] = j;             // track the previous index
                }
            }

            // Track the index where the largest subset ends
            if (result[i] > result[maxIndexes]) {
                maxIndexes = i;
            }
        }

        // Step 3: Reconstruct the subset from the 'previous' array
        vector<int> results;
        for (int i = maxIndexes; i >= 0; i = previous[i]) {
            results.push_back(nums[i]);
            if (previous[i] == -1) break; // stop if there's no previous
        }

        // Reverse to return the subset in correct order
        reverse(results.begin(), results.end());
        return results;
    }
};
