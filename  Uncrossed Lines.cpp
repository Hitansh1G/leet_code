class Solution {
public:
    int helper(vector<int>&nums1,vector<int>&nums2,vector<vector<int>>& ans,int i,int j){
        
        if(i>=nums1.size() || j>=nums2.size()) return 0;
        if(ans[i][j]!= -1) return ans[i][j];
        int localAns = 0;
        if(nums1[i]==nums2[j]) localAns = 1 + helper(nums1,nums2,ans,i+1,j+1);
         localAns = max({localAns,helper(nums1,nums2,ans,i+1,j),helper(nums1,nums2,ans,i,j+1)});
        return ans[i][j] = localAns;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(nums1.size(),vector<int>(nums2.size(),-1));
        return helper(nums1,nums2,ans,0,0);
        
    }
};