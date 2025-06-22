class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();  // Get the length of the input string
        vector<string> results;  // To store the final substrings
        string temp = "";  // Temporary string to build substrings

        // Loop through each character in the string
        for (int i = 0; i < n; i++) {
            temp += s[i];  // Add current character to temp

            // When temp has k characters, push to result and reset temp
            if (temp.size() == k) {
                results.push_back(temp);  // Add the full substring to results
                temp = "";  // Reset temp to start a new substring
            }
        }

        // After the loop, if temp still has characters but less than k
        if (!temp.empty()) {
            // Add fill characters until temp becomes size k
            while (temp.size() < k) {
                temp += fill;  // Append fill character
            }
            results.push_back(temp);  // Add the padded substring to results
        }

        return results;  // Return the final list of substrings
    }
};
