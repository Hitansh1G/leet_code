class Solution {
public:
    string helper(int n){
        if(n==1){
            return "0";
        }
        string s = helper(n-1);
        string ans=s+'1';
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='0'){
                s[i]='1';
            }
            else s[i]='0';
        }
        reverse(s.begin() ,s.end());
        ans+=s;

        return ans;
    }
    char findKthBit(int n, int k) {
        string s = helper(n);
        return s[k-1];
        
    }
};