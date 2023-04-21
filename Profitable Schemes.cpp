class Solution {
public:
    int countWays(int i,int n,int currProfit,int minProfit,
                vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp){
        if(n < 0) 
            return 0; 

        if(i < 0 && currProfit >= minProfit && n >= 0)
            return 1;
        else if(i < 0) 
            return 0;

        if(dp[i][n][currProfit] != -1)
            return dp[i][n][currProfit];

        int take = countWays(i-1,n-group[i],min(currProfit+profit[i],minProfit),minProfit,group,profit,dp); 

        int notTake = countWays(i-1,n,currProfit,minProfit,group,profit,dp);
  
        return dp[i][n][currProfit] = (take + notTake)%1000000007;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int i = group.size();
        int currProfit = 0;
        vector<vector<vector<int>>> dp(i,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return countWays(i-1,n,currProfit,minProfit,group,profit,dp)%1000000007;
    }
};