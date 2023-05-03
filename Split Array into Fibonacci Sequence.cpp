class Solution {
public:
    vector<int>ans;
    bool helper(string s, int start){
        if(start==s.size() and ans.size()>2) return true;
        long long n=0;
        for(int i=start ; i<s.size() ; i++){
            n = n*10+(s[i]-'0');
            if(n<0 or n>INT_MAX )return false;
            if(ans.size()<2 || (long long)ans.back()+(long long)ans[ans.size()-2]==n){
                ans.push_back(n);
                if(helper(s,i+1))return true; 
                ans.pop_back();
            }
            if(s[i]=='0' and i==start)return false;
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        helper(num,0);
        
        
        return ans;
    }
};