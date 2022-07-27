class Solution {
public:
    void gen(int i,string s,string& ans,unordered_map<string,int> m){
        if(ans!="") return;
        if(i==0){
            if(m.find(s)==m.end()){  
                ans=s;  
            }
            return;
        }
        gen(i-1,s+'0',ans,m);
        gen(i-1,s+'1',ans,m); 
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> m;
        for(auto i:nums)
            m[i]++;
        string ans="";
        gen(nums.size(),"",ans,m);
        return ans;
    }
};