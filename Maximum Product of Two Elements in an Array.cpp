class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int a=nums[n-1];
        int b=nums[n-2];
        return (a-1)*(b-1);
    }
};