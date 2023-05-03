class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& prices, int i, bool buy){
        if(i >= prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int cooling = helper(prices,i+1,buy); 
        if(buy){
            int buying = helper(prices,i+1,false) - prices[i]; 
            dp[i][buy] = max(buying,cooling);
        }
        else{
            int selling = helper(prices,i+2,true) + prices[i]; 
            dp[i][buy] = max(selling,cooling);
        }
            return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return helper(prices,0,true);
    }
};