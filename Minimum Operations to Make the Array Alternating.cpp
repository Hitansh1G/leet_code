class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int n=nums.size();
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        int c1=0,c2=0;
        for(int i=0;i<n;i+=2){
            m1[nums[i]]++;c1++;
        } 
        for(int i=1;i<nums.size();i+=2){
            m2[nums[i]]++;c2++;
        } 
        priority_queue<pair<int,int>> p1;
        priority_queue<pair<int,int>> p2;
        for(auto& x: m1) p1.push({x.second,x.first});
        for(auto& x: m2) p2.push({x.second,x.first});
        auto k1=p1.top();auto k2=p2.top();
        int res=INT_MAX;
        if(k1.second!=k2.second){
            res=min(res,(c1-k1.first)+c2-k2.first);
        }
        else{
            if(p1.size()==1 and p2.size()==1) return n/2;
            p1.pop();
            if(p1.size()) res=min(res,(c1-p1.top().first)+c2-p2.top().first);
            p1.push(k1);
            p2.pop();
            if(p2.size()) res=min(res,(c1-p1.top().first)+c2-p2.top().first);
        }
        return res;
    }
};