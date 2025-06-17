class Solution {
public:
    // Function to check if the usage of capitals in the word is correct
    bool detectCapitalUse(string word) {
        int n = word.size();  // Get the length of the word
        int upperCount = 0;   // Counter for uppercase letters

        // Loop through each character to count uppercase letters
        for(int i = 0; i < n; i++) {
            if(isupper(word[i])) {
                upperCount++;  // Increment if the character is uppercase
            }
        }

        // Case 1: All letters are uppercase (e.g., "USA")
        if(upperCount == n) {
            return true;
        }
        // Case 2: All letters are lowercase (e.g., "leetcode")
        else if(upperCount == 0) {
            return true;
        }
        // Case 3: Only the first letter is uppercase (e.g., "Google")
        else if(upperCount == 1 && isupper(word[0])) {
            return true;
        }
        // Case 4: Any other mixed use of capitals is invalid
        else {
            return false;
        }
    }
};
