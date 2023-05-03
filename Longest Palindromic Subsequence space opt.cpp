class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n;
        n = s.size();
        vector<int> dp(n,0) , curr(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i]==t[j]) curr[j] = 1+ ((i-1)<0?0:(j-1)<0?0:dp[j-1]);
                else curr[j] = max(((i-1)<0?0:dp[j]),(j-1)<0?0:curr[j-1]);
            }
            dp = curr;
        }
        return dp[n-1];
    }
};