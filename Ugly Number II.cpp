class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1,0); 
        int count_2=1;
        int count_3=1;
        int count_5=1;
        int val_2;
        int val_3;
        int val_5;
        int min_val;
        dp[1]=1; 
        for(int i=2;i<=n;i++){
            val_2=2*dp[count_2];
            val_3=3*dp[count_3];
            val_5=5*dp[count_5];
            min_val=min(val_2,min(val_3,val_5));
            if(min_val==val_2){
                count_2++;
            }
            if(min_val==val_3){
                count_3++;
            }
            if(min_val==val_5){
                count_5++;
            }
            dp[i]=min_val;
        }
        return dp[n];
    }
};