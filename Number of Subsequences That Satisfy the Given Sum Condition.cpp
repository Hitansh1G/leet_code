class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans=0,mod=1000000007, start=0, end=nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<int> pow2(nums.size()+1,1);
        for(int i=1;i<=nums.size();i++)
        {
            pow2[i]=(2*pow2[i-1])%mod;
        }
        while (start<=end) {
            if (nums[start]+nums[end]<=target) {
                ans=(ans+pow2[end-start])%mod;
                start++;
            }
            else end--;
        }
        return ans;
    }
};