class Solution {
public:
    int climbStairs(int n) {
        int dp[n+2];
        dp[0] = 0;
        for(int i=1 ; i<=n+1 ; i++){
            if(i==1)  dp[i] = dp[i-1]+1;
            else dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n+1];
    }
};