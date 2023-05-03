class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(string i:nums){
            int cur=0;
            for(int j=n-1;j>=0;j--){
                if(i[j]-'0'==1){
                    cur=cur | 1<<(n-1-j);
                }
            }
            m[cur]=1;
        }
        string ans="";
        for(int i=0;i<=n;i++){
            if(m[i]==0){
                bitset<16>bs(i);
                for(int j=n-1;j>=0;j--){
                    if(bs[j]^1) ans+="0";
                    else{
                        ans+="1";
                    }
                }
                
                break;
            }
        }
        return ans;
    }
};