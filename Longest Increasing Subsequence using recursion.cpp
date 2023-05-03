class Solution {
public:
    int f(int ind , int prev , vector<int>& nums , int n){
        if(ind == n){
            return 0;
        }
        int len = 0 + f(ind+1,prev, nums,n);
        if(prev == -1 || nums[ind]>nums[prev]){
            len = max(len,1+f(ind+1,ind,nums,n));
        }
        return len;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return f(0,-1,nums,n);
    }
};