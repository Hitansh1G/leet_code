class Solution {
public:
    int modd = 1e9 + 7;
    
    int f(vector<string>& dice, vector<vector<vector<int>>>& dp, int n, int pp, int p){
        if(n == 0){
            return 1;
        }
        
        if(dp[n][pp][p] != 0)
            return dp[n][pp][p];
        
        int count = 0;
        for(int i=1 ; i<7 ; ++i){
            if(i != pp && i != p && (p == 0 || dice[p][i] == '1')){
                count = (count + f(dice, dp, n - 1, p, i) % modd) % modd;
            }
        }
        
        return dp[n][pp][p] = count ;
    }
    
    int distinctSequences(int n) {
        if(n == 1)
            return 6;

        vector<string> dice = {"", "5011111" ,"3101010" ,"4110110" ,"3101010" ,"5111101" ,"2100010" };
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(7, vector<int>(7, 0)));
            
        return f(dice, dp, n, 0, 0);
    }
};