class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        if(n!=0){
            for(int i=0;i<n;i++){
                int curr = asteroids[i];
                bool destroyed = false;

                while(!st.empty() && curr<0 && st.top()>0){
                    if(abs(curr) > st.top()){
                        st.pop();
                    }
                    else if(abs(curr)==st.top()){
                        st.pop();
                        destroyed = true;
                        break;
                    }
                    else{
                        destroyed = true;
                        break;
                    }
                }
                if(!destroyed){// If current asteroid is not destroyed, push it to stack
                    st.push(curr);
                }
            }
        }

        vector<int> result(st.size());//Convert stack to vector in reverse order
        for(int i=st.size()-1;i>=0;i--){
            result[i]=st.top();
            st.pop();
        }
        return result;
    }
};
