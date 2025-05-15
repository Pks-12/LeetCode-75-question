class Solution {
public:
    string removeStars(string s) {
        string result="";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                result.push_back(s[i]);
            }
            else{
                if(!result.empty()){
                    result.pop_back();
                }
            }
        }
            return result;
    }
};
