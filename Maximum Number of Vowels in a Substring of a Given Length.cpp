class Solution {
public:

    // Helper function to check if a character is a vowel
    bool isVowel(char ch){
        ch = tolower(ch); // Convert to lowercase for uniform comparison
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.size(); // Length of the string
        int maxCount = 0;       // Stores the maximum number of vowels found in any window
        int currentCount = 0;   // Vowel count in the current window

        // Check if string is not empty
        if (n != 0) {

            // Count vowels in the first window of size k
            for (int i = 0; i < k; i++) {
                if (isVowel(s[i])) {
                    currentCount++;
                }
            }

            // Initialize maxCount with the count of first window
            maxCount = currentCount;

            // Now slide the window one character at a time
            for (int i = k; i < n; i++) {

                // Add new character at the end of window
                if (isVowel(s[i])) {
                    currentCount++;
                }

                // Remove character that goes out of window
                if (isVowel(s[i - k])) {
                    currentCount--;
                }

                // Update maxCount if current window has more vowels
                if (currentCount > maxCount) {
                    maxCount = currentCount;
                }
            }
        }

        return maxCount; // Return the maximum number of vowels found in any window
    }
};
