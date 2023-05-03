class Solution {
public:

    void helper(vector<int>& nums , int i, vector<int>curr ,  vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        vector<int>temp = curr;
        temp.push_back(nums[i]);
        helper(nums,i+1,temp,ans);
        helper(nums,i+1,curr,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(nums,0 , temp,ans);
        return ans;
    }
};