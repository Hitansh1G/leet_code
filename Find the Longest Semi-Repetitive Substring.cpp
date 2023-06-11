class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i = 0, j = 0, n = s.length(),ans=0,x=0;
        vector<int> v(10,0);
        while(i<n){
            v[s[i]-'0']++;
            if(i && s[i]==s[i-1]){
                x++;
            }
            while(x>1){
                x -= (s[j]==s[j+1]);
                v[s[j]-'0']--;
                j++;
            }
            ans = max(ans,i-j+1);
            i++;
        }
        return ans;
            
    }
};