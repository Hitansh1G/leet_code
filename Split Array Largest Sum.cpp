class Solution {
public:
    bool ispossible(vector<int>&nums,int m,int mid){
        int spiliting=1;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>mid){
                return false;
            }
            if(nums[i]+sum>mid){
                spiliting++;
                sum=nums[i];
            }
            else{
                sum=sum+nums[i];
            }
        }
        return spiliting<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int low=*min_element(nums.begin(),nums.end());
        long long int high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        if(nums.size()==1){
            return high;
        }
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(ispossible(nums,m,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};