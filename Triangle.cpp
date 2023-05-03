class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int base=tri[tri.size()-1].size();
        vector<int> dp(base,0);
        cout<<base;
        for(int i=base-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                
                if(i==base-1)
                    dp[j]=tri[i][j];
                
                else{                    
                    int down=dp[j];
                    int diag=dp[j+1];
                    dp[j]=tri[i][j]+min(down,diag);
                    dp.pop_back();
                }               
            }
        }
        return dp[0];        
    }
};