class Solution {
public:
    
    int dp[305][305];
    int ans;
    
    int getMax(vector<vector<char>>& mat, int i, int j){
        int n=mat.size(), m=mat[0].size();
        if(i>=n || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = min({getMax(mat, i, j+1), getMax(mat, i+1, j), getMax(mat, i+1, j+1)}) + 1;
        if(mat[i][j] == '0') dp[i][j] = 0;
        ans = max(ans, dp[i][j]);
		
        return dp[i][j];
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp, -1, sizeof(dp));
        ans = 0;
        getMax(matrix, 0, 0);
        return ans*ans;
    }
};