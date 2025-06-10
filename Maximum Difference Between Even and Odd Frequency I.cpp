class Solution {
public:
    int maxDifference(string s) {
        // Step 1: Create a frequency array for all 26 lowercase letters
        vector<int> freq(26, 0);

        // Step 2: Count the frequency of each character in the string
        for (char c : s) {
            freq[c - 'a']++;  // 'a' maps to 0, 'b' to 1, ..., 'z' to 25
        }

        // Step 3: Initialize variables to track:
        // maxOdd: maximum frequency among characters with odd counts
        // minEven: minimum frequency among characters with even counts
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        // Step 4: Iterate through the frequency array
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;  // Skip characters not present in the string

            if (freq[i] % 2 == 1) {
                // If frequency is odd, update maxOdd
                maxOdd = max(maxOdd, freq[i]);
            } else {
                // If frequency is even, update minEven
                minEven = min(minEven, freq[i]);
            }
        }

        // Step 5: Return the difference between maxOdd and minEven
        // The problem guarantees that at least one odd and one even frequency exists
        return maxOdd - minEven;
    }
};
