class Solution {
public:
    int solve(vector<int>&nums, int target, int sum, vector<int>&dp){
        if(target == sum)
            return 1;
        if(target<sum)
            return 0;
        if(dp[sum] == -1){
            int ans = 0;
            for(int i =0 ; i<nums.size(); i++){
                ans += solve(nums,target,sum+nums[i],dp);
            }
            dp[sum]=ans;
        }
        return dp[sum];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int maxm = INT_MIN;
        for(auto i :nums){
            maxm = max(i, maxm);
        }
        vector<int>dp(target+maxm+1,-1);
        return solve(nums,target, 0, dp);
    }
};