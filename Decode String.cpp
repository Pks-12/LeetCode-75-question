class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string> st;
        stack<int> cS;
        string cs="";
        int k=0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(isdigit(ch)){
                k=k*10+(ch - '0');
            }
            else if(ch == '['){
                cS.push(k);
                st.push(cs);
                cs="";
                k=0;
            }else if(ch == ']'){
                string decodedString = st.top();
                st.pop();
                int currentK = cS.top();
                cS.pop();
                while(currentK-- >0){
                    decodedString += cs;
                }
                cs = decodedString;
            }
            else{
                cs+=ch;
            }
        }
        return cs;
    }
};
