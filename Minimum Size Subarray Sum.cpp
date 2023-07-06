class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, window = 0;
        int res = INT_MAX;

        for(right = 0; right < nums.size(); right++) {
            window += nums[right];

            while (window >= target) {
                res = min(res, right - left + 1);
                window -= nums[left];
                left++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};