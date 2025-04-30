class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx=0;
        for(int i=0;i<n;i++){
            char ch=chars[i];
            int c=0;
            while(i<n&&chars[i]==ch){
                c++;
                i++;
            }
            if(c==1){
                chars[idx++]=ch;
            }
            else{
                chars[idx++]=ch;
                string str=to_string(c);
                for(char dig : str){
                    chars[idx++]=dig;
                }
            }
            i--;
        }
            chars.resize(idx);
            return idx;
    }
};
