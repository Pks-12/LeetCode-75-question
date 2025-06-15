class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0); // count of each character
        vector<bool> inStack(26, false); // to check if character is already in result
        string result = "";

        // Step 1: Count each character
        for (char c : s) {
            count[c - 'a']++;
        }

        // Step 2: Iterate through the string
        for (char c : s) {
            count[c - 'a']--; // use this character

            if (inStack[c - 'a']) continue; // already in result, skip

            // Remove characters that are greater than current and will appear again
            while (!result.empty() && c < result.back() && count[result.back() - 'a'] > 0) {
                inStack[result.back() - 'a'] = false; // mark as not in result
                result.pop_back(); // remove last character
            }

            result.push_back(c); // add current character
            inStack[c - 'a'] = true; // mark as added
        }

        return result;
    }
};
