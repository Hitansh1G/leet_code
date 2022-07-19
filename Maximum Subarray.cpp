class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long sum=0,curr=0,flag=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            sum=max(sum,curr);
            if(curr<0)curr=0;
            if(flag==0 && nums[i]>0){
                flag=1;
            }
        }
        if(flag==0) return *max_element(nums.begin(),nums.end());
        return sum;
    }
};