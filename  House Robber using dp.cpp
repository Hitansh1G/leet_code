class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        for(int i=2 ; i<n ; i++){
            if(i-2 >= 0 && i-3>=0){
                nums[i] = max(nums[i-2]+nums[i] , nums[i-3]+nums[i]);
            }
            else if(i-2 >= 0 ){
                nums[i]  = nums[i]+nums[i-2];
            }          
        }
        return max(nums[n-1],nums[n-2]);
    }
};