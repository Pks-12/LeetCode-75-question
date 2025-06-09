class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();//  find the size of strs.
        unordered_map<string, vector<string>> map;// key = sorted word, value = list of anagrams
        sort(strs.begin(),strs.end());
        for(int i=0;i<n ;i++){
            string word = strs[i];// original word
            string sortedWord = word; // make a copy to sort
            sort(sortedWord.begin(),sortedWord.end());// sort characters to get the key
            map[sortedWord].push_back(word); // group anagram under sorted key
        }
        // Convert the map to a vector of vectors
        vector<vector<string>> result;
        for(auto& entry:map){
            result.push_back(entry.second);// add each group to result
        }
        return result;
    }
};
