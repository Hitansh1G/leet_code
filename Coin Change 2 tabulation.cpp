class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)
                dp[0][t]= 1;
            else dp[0][t]= 0;
        }
        
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                
                int take=0;
                int notTake= dp[i-1][tar];
                if(tar>=coins[i])
                    take= dp[i][tar-coins[i]];
                 dp[i][tar]= (take+notTake);
            }
        }
       return dp[n-1][amount];
        
    }
};