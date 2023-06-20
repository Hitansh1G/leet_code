class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>avg(n,-1);
        vector<long long>prefix(n+1,0);
        if(k==0)return nums;
        // if(2*k+1 > n)return vec;

        for(int i=0 ; i<n ; i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        for(int i=k ; i<n-k ; i++){
            long long left = i-k;
            long long right = i+k;

            long long sum = prefix[right+1]-prefix[left];
            int avgsum = sum/(2*k+1);

            avg[i] = avgsum;
        }
        return avg;
    }
};