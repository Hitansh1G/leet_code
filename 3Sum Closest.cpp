class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
		int res, ans = INT_MAX - 10000;
		sort(begin(nums), end(nums));
		for (int i = 0; i < nums.size(); ++i) {
			int l = i + 1, h = nums.size() - 1;
			while (l < h) {
				res = nums[i] + nums[l] + nums[h];
				if (res == target) {
					return res;
				} else if (res < target) {
					++l;
				} else {
					--h;
				}
				if (abs(target - ans) > abs(res - target)) {
					ans = res;
				}
			}
		}
		return ans;
    }
};