class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(i==j || arr[i]!=2*arr[j]){// or more conditionif(i!=j && arr[i]==2*arr[j])
                continue;                   //  then no continue
        }
                return true;        //  direct return the true value
        }
        }
        return false;
    }
};
