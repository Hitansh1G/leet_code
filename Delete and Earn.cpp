class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max1 = *max_element(nums.begin(),nums.end());
        vector<int> f(max1+1,0);
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        for(int i=0;i<f.size();i++){
            f[i]=f[i]*i;
        }
        int pr=f[0];
        int  p=f[1];
        for(int i=2;i<f.size();i++){
            int take=f[i];
            take+=pr;
            int ntake=p;
            int cur=max(take,ntake);
            pr=p;
            p=cur;
        }
        return p;
    }
};