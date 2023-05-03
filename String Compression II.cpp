class Solution {
public:
    int n,k,dp[101][101];
    string s;
    
    int len(int n){
        if(n==1) return n;
        else return (int)(1+(bool)(n/1)+(bool)(n/10)+(bool)(n/100));
    }
    
    int sol(int i,int del){
        if(del>k) return 1e9;
        if(i>=n) return 0;
        
        int ans=dp[i][del];
        if(ans!=-1) return ans;
        ans=sol(i+1,del+1);
        
        int same=0,curdel=0;
        for(int j=i;j<n;j++){
            if(s[j]==s[i]) same++;
            else curdel++; 
            ans=min(ans,len(same)+sol(j+1,del+curdel));
        }
        
        return dp[i][del]=ans;
    }
    
    int getLengthOfOptimalCompression(string ss, int kk) {
        s=ss;
        n=ss.length(); k=kk;
        memset(dp,-1,sizeof(dp));
        return sol(0,0);
    }
};
