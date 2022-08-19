class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        for(int i=0;i<=text1.size();i++)dp[i][0]=0;
        for(int i=0;i<=text2.size();i++)dp[0][i]=0;
        
        for(int ind1=1;ind1<=text1.size();ind1++){
            for(int ind2=1;ind2<=text2.size();ind2++){
                if(text1[ind1-1]==text2[ind2-1])dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};