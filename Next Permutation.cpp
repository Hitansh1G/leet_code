class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        if( n < 1) return ;
        int index1=-1;
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i] < nums[i+1]){
                index1 = i;
                break;
            }
        }
        if(index1 >= 0){
            int j =n-1;
            while(j>index1){
                if(nums[index1] < nums[j]){
                    swap(nums[index1],nums[j]);
                    break;
                }
                j--;
            }
            reverse(nums.begin()+index1+1,nums.end());
        }
        else{
            reverse(nums.begin(),nums.end());
        }
    }
};  