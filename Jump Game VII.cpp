class Solution {
public:
    bool canReach(string s, int mn, int mx) {
        int n = s.size();
        vector<bool>dp(n,false);
        dp[0] = true; 
        int c = 0;
        for(int i=1;i<n;i++){
            if(i>=mn) c+=dp[i-mn];
            if(i>mx) c-=dp[i-mx-1];

            dp[i] = (s[i]=='0') && (c>0); 
        }
        return dp[n-1];
    }
};