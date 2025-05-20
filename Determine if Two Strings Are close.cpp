

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // If the lengths of the two words are different, they can't be close.
        if (word1.size() != word2.size()) {
            return false;
        }
        
        // Step 1: Check if both strings have the same unique characters
        unordered_set<char> set1(word1.begin(), word1.end());
        unordered_set<char> set2(word2.begin(), word2.end());
        
        if (set1 != set2) {
            return false;
        }
        
        // Step 2: Count the frequency of each character in both strings
        unordered_map<char, int> freq1, freq2;
        
        for (char c : word1) {
            freq1[c]++;
        }
        for (char c : word2) {
            freq2[c]++;
        }
        
        // Step 3: Check if the frequencies match (ignoring order)
        vector<int> freq1Values, freq2Values;
        
        for (const auto& pair : freq1) {
            freq1Values.push_back(pair.second);
        }
        for (const auto& pair : freq2) {
            freq2Values.push_back(pair.second);
        }
        
        // Sort the frequency arrays
        sort(freq1Values.begin(), freq1Values.end());
        sort(freq2Values.begin(), freq2Values.end());
        
        // If the frequency distributions match, return true
        return freq1Values == freq2Values;
    }
};
