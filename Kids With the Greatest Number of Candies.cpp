class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxCandies = INT_MIN;
        for(int i=0;i<n;i++){
            if(candies[i]>maxCandies){
                maxCandies=candies[i];
            }
        }
        vector<bool>output;
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxCandies){
                output.push_back(true);
            }
            else{
                output.push_back(false);
            }
        }
        return output;
    }
};
