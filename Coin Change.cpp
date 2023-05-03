class Solution {
public:
    int f(int i,vector<int>&coins,int amount, vector<vector<int>>&dp){
       if(amount==0)return 0;
        if(i==coins.size() || amount<0)return INT_MAX-1;
       if(dp[i][amount]!=-1)return dp[i][amount];
        int take=INT_MAX;
        if(amount>=coins[i]){
            take=1+f(i,coins,amount-coins[i],dp);
        }
        int skip=f(i+1,coins,amount,dp);
        
        return dp[i][amount]=min({take,skip});
    }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int x=f(0,coins,amount,dp);
        if(x==INT_MAX-1)return -1;
        return x;
    }
};