class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0'){
            return 0;
        }
        for(int i=0;i<n-1;++i){
            if(s[i]==s[i+1]&&s[i]=='0'){
                return 0;
            }
        }
        int dp[n][2];
        dp[0][0]=1;
        dp[0][1]=0;
        for(int i=1;i<n;++i){
            if(s[i]!='0')dp[i][0]=(dp[i-1][0]+dp[i-1][1]);
            else{
                dp[i][0]=0;
            }
            if(s[i-1]=='0'){
                dp[i][1]=0;
            }
            else{
                int v=(s[i-1]-'0')*10+(s[i]-'0');
                if(v>=1&&v<=26){
                    if(i-2>=0)dp[i][1]=(dp[i-2][0]+dp[i-2][1]);
                    else dp[i][1]=1;
                }
                else{
                    dp[i][1]=0;
                }
            }
            
        }
        return dp[n-1][0]+dp[n-1][1];
    }
};