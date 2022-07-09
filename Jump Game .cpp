class Solution {
public:
    bool helper(vector<int>& nums,int ind,vector<int>& dp){
        int n=nums.size();
        if(ind==n-1) return true;
        if(dp[ind]!=-1) return dp[ind];

        for(int k = 1+ind;k<=nums[ind]+ind;k++){
            if(helper(nums,k,dp)) return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(nums,0,dp);
    }
};