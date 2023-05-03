class Solution {
public:
    set<vector<int>> st;
    
    void createSubset(vector<int>& nums){
        int n=nums.size();
        int limit=pow(2,n);
        
        int x=0;
        while(x<limit){
            vector<int>v;
            int ind=0,tmp=x;
            while(tmp){
                if(tmp&1)
                    v.push_back(nums[ind]);
                tmp=tmp>>1;
                ind++;
            }
            sort(v.begin(),v.end());
            st.insert(v);
            x++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        createSubset(nums);
        vector<vector<int>>ans;
        
        for(auto i:st)
            ans.push_back(i);
        return ans;
    }
};