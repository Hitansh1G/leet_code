class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(); 
        vector<int> ans(n,1);
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        vector<int> ans2(n,1);
        for(int j=n-2;j>=0;j--){
            ans2[j]=ans2[j+1]*nums[j+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=ans[i]*ans2[i];
        }
        return ans;

    }
};