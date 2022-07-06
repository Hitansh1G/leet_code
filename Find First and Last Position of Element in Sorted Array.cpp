class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //we will find the left most val of tar
        //and the right most val of tar
        //store them
        //for left bs the target and continue to do so .. bs right wali pointer ko mid-1 krke bhi check kro if tis 
        int n=nums.size();
        int left=0;
        int right =n-1;
        int first=-1;
        while(right>=left){
            int mid = (right+left)/2;
            if(nums[mid]==target){
                first=mid;
                right = mid-1;
            }
            else if(nums[mid]>target){
                right= mid-1;   
            }
            else left = mid+1;
        }
        left=0;
        right = n-1;
        int last = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target){
                last = mid;
                left = mid+1;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else left=mid+1;
        }
        return{first,last};
    }
};