class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // int left=0;
        // int right=0;
        int sum =0;
        int n =nums.size();
        int k=0;
        
        for(auto it:nums){
            sum +=it;
        }
        for(int i=0 ; i<n ; i++){
            if(sum-nums[i] == 2*k)
                return i;
            k += nums[i];
        }
        return -1;
    }
};