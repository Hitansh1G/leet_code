class Solution {
public:
	bool solve(string&s,string&p,int i,int j,int n,int m,vector<vector<int>>&dp){
		if(i>=n&&j>=m) return true;                       
		if(j>=m) return false;                                  
		if(dp[i][j] != -1) return dp[i][j];
		bool match = i < n and ( s[i] == p[j] or p[j]=='.');     
		if(j+1 < m and p[j+1] == '*'){
			return dp[i][j] = solve(s,p,i,j+2,n,m,dp) or (match and solve(s,p,i+1,j,n,m,dp));   
		}
		if(match) return dp[i][j] = solve(s,p,i+1,j+1,n,m,dp);   
		return dp[i][j] = false;
	}
	bool isMatch(string s, string p) {
		int n = s.size(),m=p.size();
		vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
		return solve(s,p,0,0,n,m,dp);
	}
};