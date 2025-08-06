class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Step 1: Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans; // This will store the merged intervals

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];  // Start of current interval
            int end = intervals[i][1];    // End of current interval

            // Optimization: if the current interval is already merged (i.e., lies inside the last one in ans)
            if (!ans.empty() && end <= ans.back()[1]) {
                continue; // Skip it
            }

            // Check if the current interval overlaps with the next intervals
            for (int j = i + 1; j < n; j++) {
                // If the next interval starts before or at current 'end', they overlap
                if (intervals[j][0] <= end) {
                    // Merge by extending the end to the max end seen so far
                    end = max(end, intervals[j][1]);
                } else {
                    // If there's no overlap, stop checking further
                    break;
                }
            }

            // Add the merged interval to result
            ans.push_back({start, end});
        }

        return ans;
    }
};
