class Solution {
public:
    int integerBreak(int n) {
     vector<int> dp(n+1)   ;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;++i){
            int maxi=0;
            for(int j=i-1;j>0;j--){
                maxi=max(maxi,dp[j]*(i-j));
                maxi=max(maxi,j*(i-j));
            }
            dp[i]=maxi;
        }
        return dp[n];
    }
};