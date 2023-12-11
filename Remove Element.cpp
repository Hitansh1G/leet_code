class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>sol;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val)sol.push_back(nums[i]);
        }
        nums = sol;
        return sol.size();
    }
};