class Solution {
public:
    int check(int penalty, vector<int> &nums) {
        int ans=0 ;
        for(int x : nums) if(x > penalty) ans+=(x+penalty-1)/penalty-1 ;
        return ans;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(),nums.end());
        int lo=1,hi=nums.back(),ans=nums.back();
        while(lo<=hi) {
            int mid = (lo+hi)>>1 ;
            if(check(mid,nums) <= maxOperations) {
                ans = min(ans,mid);
                hi=mid-1 ;
            } 
            else lo=mid+1 ;
        }
        return ans ;
    }
};