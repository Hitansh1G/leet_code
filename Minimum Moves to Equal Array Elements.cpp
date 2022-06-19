class Solution {
public:
    int minMoves(vector<int>& nums) {
        //check how which element has the most frequency then subrct it from size
        sort(nums.begin(), nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans+nums[i]-nums[0];
        }
        return ans;
        
    }
};