class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=n-2 ; i>=0 ; i--){
            int ans=1e9;
            for(int j=1 ; j<=nums[i] && j+i<n ; j++){
                ans=min(ans,dp[i+j]+1);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};