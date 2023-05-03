class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        vector<int> dp(s.size() + 1, 0);
        for (int l=0 , r=1 ; r<s.size() ; ++r,l=r-dp[r] - 1) {
            if (l >= 0 && s[l] == '(' && s[r] == ')') {
                dp[r + 1] = 2 + dp[l] + dp[r];
                max_len = max(max_len, dp[r + 1]);
            }
        }
        return max_len;
    }
};