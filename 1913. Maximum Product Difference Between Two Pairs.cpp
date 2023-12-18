class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        //max a*b - c*d
        //a and be max
        //c and d min
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int c=nums[0],d=nums[1];
        int a=nums[n-1],b=nums[n-2];

        return (a*b)-(c*d);
    }
};