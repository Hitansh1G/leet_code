class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> a,b,temp;
        a=values,b=values;
        
        for(int i=0;i<values.size();i++){
            a[i]+=i+1;
            b[i]-=i+1;
        }
        
        
        int mx=INT_MIN, mxl=a[0];
        
        for(int i=1;i<b.size();i++){
            mx = max(mx, mxl+b[i]);
            mxl = max(mxl,a[i]);
        }
        
        return mx;
        
    }
};