class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size(); 
        vector<int> dp(n, 1); 
        for (int i = 0; i < n; ++i) 
            for (int ii = 0; ii < i; ++ii) 
                if (nums[i] % nums[ii] == 0) 
                    dp[i] = max(dp[i], 1 + dp[ii]);
        
        auto it = max_element(dp.begin(), dp.end()); 
        vector<int> ans;
        for (int i = it - dp.begin(), val = *it; i >= 0; --i) 
            if (ans.empty() || (ans.back() % nums[i] == 0 && dp[i] == val)) {
                --val; 
                ans.push_back(nums[i]); 
            }
        reverse(ans.begin(), ans.end()); 
        return ans; 
    }
};