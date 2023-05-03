class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        int dir[][2] ={{1,2},{2,1},
                       {-1,2},{-2,1},
                       {1,-2},{2,-1},
                       {-1,-2},{-2,-1}};
        vector<vector<double>> dp(N, vector<double>(N, 1.0)), old;
        
        for(int k=1;k<=K;k++) {
            old = dp;
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++) {
                    double t=0;
                    for(auto& u :dir) {
                        int x=i+u[0], y=j+u[1];
                        if(x<0 || y<0 || x>=N ||y>=N) continue;
                        t += old[x][y]/8;
                    }
                    dp[i][j] = t;
                }
        }
        
        return dp[r][c];
    }
};