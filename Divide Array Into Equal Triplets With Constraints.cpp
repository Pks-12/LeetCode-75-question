class Solution {
public:
    /*
        Given an integer array nums and an integer k, we need to
        split nums into groups of exactly 3 elements such that
        for every group the difference between the largest and
        smallest element is ≤ k.

        If that’s impossible, we must return an empty vector.
    */
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        // Early exit: if the total number of elements isn’t a multiple of 3,
        // no valid partition exists by definition.
        if (n % 3 != 0) return {};

        /*------------------------------------------------------------
          1. Sort the array so that any contiguous block of 3 numbers
             will have its min at position i and its max at i + 2.
        ------------------------------------------------------------*/
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        /*------------------------------------------------------------
          2. Step through the array in chunks of 3.  After sorting,
             the triple {nums[i], nums[i+1], nums[i+2]} is the
             lexicographically smallest triple containing nums[i].
        ------------------------------------------------------------*/
        for (int i = 0; i < n; i += 3) {
            // nums[i]      = smallest in this triple (low)
            // nums[i + 1]  = middle element (mid)
            // nums[i + 2]  = largest in this triple (high)

            // 3. Check the constraint for this triple.
            if (nums[i + 2] - nums[i] > k) {
                // The max–min gap is too large → impossible overall.
                return {};
            }

            // 4. Otherwise, store this valid triple.
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        // 5. All triples satisfied the condition → return them.
        return ans;
    }
};
