class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0,p=0 ; i<n ; i++){
            if(nums[i]!=0){
                swap(nums[i] , nums[p++]);
            }
        }
    }
};