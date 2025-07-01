class Solution {
public:
    int possibleStringCount(string word) {
        vector<pair<char, int>> groups;
        int n = word.size(), i = 0;

        // Step 1: Group consecutive characters
        while (i < n) {
            char ch = word[i];
            int j = i;
            while (j < n && word[j] == ch) j++;
            groups.push_back({ch, j - i});
            i = j;
        }

        int count = 1; // Original word itself is valid

        // Step 2: Try shortening each group (only one allowed)
        for (int k = 0; k < groups.size(); ++k) {
            int len = groups[k].second;
            // We can reduce this group to any length from 1 to (len - 1)
            for (int reduceLen = 1; reduceLen < len; ++reduceLen) {
                count++;
            }
        }

        return count;
    }
};
