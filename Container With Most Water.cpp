class Solution {
public:
    int maxArea(vector<int>& height) {
    //     int mW=0;
    //     int n=height.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             int w=j-i;//TLE
    //             int ht=min(height[i],height[j]);
    //             int cW=w*ht;
    //             mW=max(mW,cW);
    //         }
    //     }
    //     return mW;

    int l=0;
    int r=height.size()-1;
    int mA=0;
    while(l<r){
        int h=min(height[l],height[r]);
        int w=r-l;
        int a=h*w;
        mA=max(mA,a);
        if(height[l]<height[r]){
            l++;
        }
        else{
            r--;
        }
    }
    return mA;
    }
};
