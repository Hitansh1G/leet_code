class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool flag = false;
        int n=nums.size();
        int end = n-1;
        int target = end;
        for(int i=end ; i>=0 ; i--){
            if(nums[i]>=target-i){
                flag = true;
                target = i;
            }
            else flag = false;

        }
        return flag;
    }
};