class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size(); // Get the size of the array
        int count[1000] = {0}; // Create an array to count occurrences of each number (0 to 999)

        // Step 1: Count how many times each number appears in the array
        for (int i = 0; i < n; i++) {
            count[arr[i]]++; // Increase the count of the current number
        }

        int lucky = -1; // Initialize lucky number as -1 (in case no lucky number is found)

        // Step 2: Check if any number has a count equal to its value
        for (int i = 1; i <= 500; i++) { // Loop from 1 to 500 (since numbers > 500 are not expected)
            if (count[i] == i) {
                lucky = i; // Update the lucky number (we keep the largest one because loop goes from 1 to 500)
            }
        }

        return lucky; // Return the largest lucky number found, or -1 if none found
    }
};
