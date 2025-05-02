class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int p=0;
            for(int j=0;j<m;j++){
                if(p<n && s[p]==t[j]){
                    p++;
                }
            }
        
            return p == n;
    }
};
