class Solution {
public:
   int f(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(i>=s.length()||j>=t.length()) return false;
        if(i==s.length()-1){
            if(s[i]==t[j]) return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool a=false,b=false;
        if(s[i]==t[j])
            a=a||f(i+1,j+1,s,t,dp);
        b=b||f(i,j+1,s,t,dp);
        return dp[i][j]=a||b;
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,-1));
        if(s=="") return true;
        return f(0,0,s,t,dp);
    
    }
};