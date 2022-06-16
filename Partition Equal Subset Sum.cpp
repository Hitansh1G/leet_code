class Solution {
public:
    bool subsetsum(vector<int>& arr,int sum) {
        int n = arr.size();
        bool knap[n+1][sum+1];
        for(int i=1;i<=sum;i++){
            knap[0][i]=false;
        }
        for(int j=0;j<=n;j++){
            knap[j][0] =true;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                   knap[i][j]=knap[i-1][j-arr[i-1]] || knap[i-1][j];
                }
                else{
                    knap[i][j] = knap[i-1][j];
                }
            }
        }
        return knap[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        int sum2=sum/2;
        if(sum%2!=0)
            return false;
        else
            return subsetsum(nums,sum2);
        // return helper(nums,)
    }
};