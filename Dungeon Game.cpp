class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        int dp[n][m];
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 and j == m-1){
                    if(dungeon[i][j] >= 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = abs(dungeon[i][j]) + 1;
                    }
                }

                else if(i == n-1){
                    if(dungeon[i][j] > 0){
                        dp[i][j] = (dp[i][j+1] - dungeon[i][j]) <= 0 ? 1 : dp[i][j+1]-dungeon[i][j];
                    }
                    else if(dungeon[i][j] <= 0){
                        dp[i][j] = dp[i][j+1] + abs(dungeon[i][j]);
                    }
                }

                else if(j == m-1){
                    if(dungeon[i][j] > 0){
                        dp[i][j] = (dp[i+1][j] - dungeon[i][j]) <= 0 ? 1 : dp[i+1][j]-dungeon[i][j];
                    }
                    else if(dungeon[i][j] <= 0){
                        dp[i][j] = dp[i+1][j] + abs(dungeon[i][j]);
                    }
                }

                else{
                    if(dungeon[i][j] <= 0){
                        dp[i][j] = abs(dungeon[i][j]) + min(dp[i+1][j], dp[i][j+1]);
                    }
                    else if(dungeon[i][j] > 0){
                        dp[i][j] = (min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]) <= 0 ? 1 : (min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]);
                    }
                }


            }
        }

        return dp[0][0];   
    }
};