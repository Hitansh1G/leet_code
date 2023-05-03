class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int ans =1, cnt=1;
        map <int,int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(mp.find(it.first+1) != mp.end()){
                cnt++;
                ans=max(ans,cnt);
            }
            else{
                cnt=1;
            }
        }
        return ans;
        
    }
};