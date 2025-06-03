class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();//     check the size of array
        sort(candyType.begin(),candyType.end());//  sort the array because it easy to count it makes counting unique items simple.
        int m = n/2;//  Alice allow to eat half of candies as doctor suggest them.
        int uniqueValue=1;//    Start with 1 because the first candy type is always unique
        for(int i=1;i<n;i++){
            if(candyType[i]!=candyType[i-1]){
                uniqueValue++;//    // Count a new type if it's different from the previous one
            }
        }
        return min(uniqueValue,m);// Return the minimum of unique types and allowed candies
    }
};
