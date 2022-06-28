class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        int d =0;
        for(int i=0 ; i<n-1 ; i++){
            int temp = i-d;
            if((temp%2)==0 and nums[i] == nums[i+1]){
                d++;
            }
            
        }
        if((n-d)%2==0) return d;
        else return d+1;
    }
};