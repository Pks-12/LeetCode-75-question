class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int m=0;
        int c=0;
        for(int i=0;i<n;i++){
            m=m+gain[i];
            if(m>c){
                c=m;
            }
        }
        return c;
    }
};
