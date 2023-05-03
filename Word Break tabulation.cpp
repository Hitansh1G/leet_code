class Solution {
public:
    bool solve(int i, string &s, int &n, unordered_set<string> &set, vector<int> &dp) {
        if(i == n) return true;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < n; j++) {
            if(set.find(s.substr(i, j - i + 1)) != set.end()) {
                if(solve(j + 1, s, n, set, dp))
                    return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> set;
        for(auto it: wordDict) set.insert(it);
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for(int i = n - 1; i >= 0; i--)
            for(int j = i; j < n; j++)
                if(set.find(s.substr(i, j - i + 1)) != set.end())
                    if(dp[j + 1]) dp[i] = true;
        return dp[0];
    }
};