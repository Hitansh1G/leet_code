class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n;
        n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i]==t[j]) dp[i][j] = 1+ ((i-1)<0?0:(j-1)<0?0:dp[i-1][j-1]);
                else dp[i][j] = max(((i-1)<0?0:dp[i-1][j]),(j-1)<0?0:dp[i][j-1]);
            }
        }
        return dp[n-1][n-1];
    }
};