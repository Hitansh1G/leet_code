class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        int left=0;
        int right=n-1;

        while(left<=right){
            int sum = nums[left]+nums[right];
            if(sum<=limit){
                left++;
                right--;
                count++;
            }
            else if(sum>limit){
                count++;
                right--;
            }
        }
        return count;
    }
};