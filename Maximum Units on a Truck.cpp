class Solution {
public:
    
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]>=v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& nums, int Size) {
        sort(nums.begin(),nums.end(),cmp);
        int ans=0;
        for(int i=0 ; i<nums.size() ; i++){
            if( Size-nums[i][0] < 0){
                ans += Size*nums[i][1];
                return ans;
            }
            ans += nums[i][0]*nums[i][1];
            Size -= nums[i][0];
        }
        return ans;
    }
};