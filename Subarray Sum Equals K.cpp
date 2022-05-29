class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        unordered_map<int,int>map;
        int curr=0;
        int count =0;
        for(int i=0 ; i<n ; i++){
            curr += nums[i];
            if(curr == k) count++;
            if(map.find(curr-k) != map.end())count += map[curr-k];
            map[curr]+=1;
        }
        return count;
    }
};