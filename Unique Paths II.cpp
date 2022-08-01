class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        long long m=grid.size();
        long long n=grid[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n,-1));
        
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                if(i==m-1 && j==n-1){
                    if(grid[i][j] != 1) dp[i][j]=1;
                    else dp[i][j]=0;
                }
                else if (i==m-1){
                    if(grid[i][j] != 1) dp[i][j]=dp[i][j+1];
                    else dp[i][j]=0;
                }
                else if(j==n-1){
                    if(grid[i][j] != 1) dp[i][j]=dp[i+1][j];
                    else dp[i][j]=0;
                }
                else{
                    if(grid[i][j] != 1) dp[i][j]=dp[i+1][j]+dp[i][j+1];
                    else dp[i][j]=0;
                }
                
            }
        }
        return dp[0][0];
    }
};