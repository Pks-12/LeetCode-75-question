class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int m = cost.size();
        int tank=0;//   total differnce between gas and cost form all across station
        int tC=0;//     tank level from current station to check
        int sI=0;//     index of the station from where the journey start
        for(int i=0;i<n;i++){
            int fG = gas[i]-cost[i];//  Net fuel at station 1
            tank = tank+fG;
            tC= tC+fG;

            if(tC<0){//     if the current tank is negative,we cannot reach the next station. 
                sI=i+1;//   try starting from the  next station
                tC=0;//     reset tank for the new start
            }
        }
        return (tank>=0)?sI:-1;//   If total gas is enough to cover total cost, return startIndex, else return -1 as given into the question.
    }
};
