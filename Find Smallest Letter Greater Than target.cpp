class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();//   Calculate the size of array.
        sort(letters.begin(),letters.end());//  Sort the array but the array is already sorted if you leave this line that's ok.
        for(int i=0;i<n;i++){// Loop throught the array.
            if(letters[i]>target){
                return letters[i];//     Return the first letter greater than target
            }
        }
        return letters[0];// If no greater letter found, wrap around and return the first letter
    }
};
