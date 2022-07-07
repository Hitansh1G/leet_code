class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        int m = -1;
        for(auto x : nums){
            if(x>0) s.insert(x);
            m = max(m,x);
        }
        if(m <= 0) return 1;
        for(int i =1;i<m;i++)
            if(s.find(i) == s.end()) return i;
        return m+1;
    }
};