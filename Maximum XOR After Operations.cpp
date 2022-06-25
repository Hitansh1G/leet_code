class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n=nums.size();
        int sol=0;
        for(int i=0 ; i<n ; i++){
            sol = sol | nums[i];
        }
        return sol;
    }
};