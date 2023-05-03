class Solution {
public:
    int dp[105];
    int solve(vector<int> & nums,int i){
        if(i<0)return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int a = solve(nums,i-2)+nums[i];
        int b = solve(nums,i-1);
        
        return max(a,b);
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        memset(dp,-1,sizeof(dp));
        return solve(nums,n);
        
    }
    
    
};