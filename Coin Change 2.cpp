class Solution {
public:
    int solve(int ind,int k,vector<int>& coins,vector<vector<int>> &dp){
        if(k==0 )
            return 1;
        if(ind==0){
            if(k%coins[ind]==0)
                return 1;
            else return 0;
        }
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        int notTake= solve(ind-1,k,coins,dp);
        int take=0;
        if(k>=coins[ind])
            take= solve(ind,k-coins[ind],coins,dp);
        return dp[ind][k]= (take + notTake);
        
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};