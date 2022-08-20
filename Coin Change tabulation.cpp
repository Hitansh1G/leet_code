class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
        int dp[coins.size()+1][amount+1];
         for(int i=0; i<amount+1; i++) dp[0][i] = INT_MAX-1;
        for(int j=1; j<coins.size()+1; j++) dp[j][0] = 0;
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                 int take=INT_MAX;
        if(j>=coins[i-1]){
            take=1+dp[i][j-coins[i-1]];
        }
        int skip=dp[i-1][j];
        
        dp[i][j]=min({take,skip});
            }
        }
        int x=dp[coins.size()][amount];
        if(x==INT_MAX-1)return -1;
        return x;
    }
};