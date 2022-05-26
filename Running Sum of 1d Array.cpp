class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>sum;
        int temp=0;
        for(int i=0 ; i<nums.size() ; i++){
            temp += nums[i];
            sum.push_back(temp);
        }
        return sum;
    }
};