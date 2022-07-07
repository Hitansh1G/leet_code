class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int x=-1;
        for(int i=1;i<=n+1;i++){
            if(mpp.find(i)==mpp.end()){
                x=i;
                break;
            }
        }
        return x;
    }
};