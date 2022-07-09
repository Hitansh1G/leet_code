class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[n-1] = true;
        for(int ind = n-2;ind>=0;ind--){
            for(int k = 1+ind;k<=nums[ind]+ind;k++){
                if(k<=n-1 && dp[k]==true){
                    dp[ind] = true;
                    break;
                }
            }	
        }
		
        return dp[0];
    }
};