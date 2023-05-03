class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count =0;
        int cur = nums[0];
        for(int i=0 ; i<n ; i++){
            if(nums[i]==cur) count++;
            if(nums[i]!=cur)count--;
            if(count<0){
                cur = nums[i];
                count=1;
            }
        }
        return cur;
    }
};