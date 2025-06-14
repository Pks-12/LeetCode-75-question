class Solution {
public:
    int minMaxDifference(int num) {
        string numStr = to_string(num);

        // --- Compute Maximum Value ---
        // Replace the first non-9 digit with 9 to maximize the number
        string maxStr = numStr;
        char toReplaceMax = ' ';
        for (char c : maxStr) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax != ' ') {
            for (char& c : maxStr) {
                if (c == toReplaceMax) {
                    c = '9';
                }
            }
        }
        int maxNum = stoi(maxStr);

        // --- Compute Minimum Value ---
        // Replace the first digit (from left) that is not '0' with '0' to minimize the number
        string minStr = numStr;
        char toReplaceMin = minStr[0];  // Always try replacing the first digit
        for (char& c : minStr) {
            if (c == toReplaceMin) {
                c = '0';
            }
        }
        int minNum = stoi(minStr);

        return maxNum - minNum;
    }
};
