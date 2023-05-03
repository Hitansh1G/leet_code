class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int base=tri[tri.size()-1].size();
        vector<vector<int>> dp(tri.size(),vector<int> (base,0));
        cout<<base;
        for(int i=base-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                
                if(i==base-1)
                    dp[i][j]=tri[i][j];
                
                else{                    
                    int down=dp[i+1][j];
                    int diag=dp[i+1][j+1];
                    dp[i][j]=tri[i][j]+min(down,diag);
                }               
            }
        }
        return dp[0][0];        
    }
};