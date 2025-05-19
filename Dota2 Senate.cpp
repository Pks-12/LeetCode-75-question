class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant;
        queue<int> dire;
        if(n!=0){
            for(int i=0;i<n;i++){
                if(senate[i]=='R'){
                    radiant.push(i);
                }
                else{
                     dire.push(i);
                }
            }
        }

        while(!radiant.empty() && !dire.empty()){
            int rIndex = radiant.front();
            int dIndex = dire.front();
            radiant.pop();
            dire.pop();

            if(rIndex< dIndex){
                radiant.push(rIndex + n);
            }
            else{
                dire.push(dIndex + n);
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
