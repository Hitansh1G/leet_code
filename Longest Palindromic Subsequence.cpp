class Solution {
public:
    int solve(int n,int m,string &s,string&t,vector<vector<int>>&dp){
        if(n<0 or m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==t[m]) return dp[n][m] = 1+ solve(n-1,m-1,s,t,dp);
        else return dp[n][m] = max(solve(n-1,m,s,t,dp),solve(n,m-1,s,t,dp));
        
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n,m;
        n = m = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n-1,n-1,s,t,dp);
    }
};