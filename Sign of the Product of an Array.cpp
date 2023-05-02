class Solution{
public:
    int arraySign(vector<int>& nums) {
        int count1=0;
        int count2=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>0){
                count1++;
            }
            else if(nums[i]<0){
                count2++;
            }
            else{
                return 0;
            }
        }
        if(count2%2==1)return -1;
        else return 1;
    }
};