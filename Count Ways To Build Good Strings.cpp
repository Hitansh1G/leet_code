class Solution {
public:
    const int mod = 1000000007;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1);
        dp[0]=1;


        for(int i=1 ; i<= high ; i++){
            if(i>=zero){
                dp[i] += dp[i-zero];
            }
            if(i>=one){
                dp[i] += dp[i-one];
            }
            dp[i] %= mod;
        }

        int ans=0;
        for(int i=low ; i<=high ; i++){
            ans += dp[i];
            ans %= mod;
        }
        return ans;

    }
};