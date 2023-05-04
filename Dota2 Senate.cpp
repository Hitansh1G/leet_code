class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        vector<bool>vis(n,0);
        int r=0,d=0,countr=0,countd=0;
        for(auto it:senate){
            if(it=='R'){
                r++;
            }
            else d++;
        }
        int i=0;
        while(r>0 &&d>0){
            if(senate[i]=='R' && vis[i]==0){
                if(countr>0){
                    countr--;
                    vis[i]=1;
                }
                else {
                    d--;
                    countd++;
                }
            }
            else if(senate[i]=='D' &&vis[i]==0){
                if(countd>0){
                    countd--;
                    vis[i]=1;
                }
                else {
                    r--;
                    countr++;
                }
            }
            i++;

            if(i==n)i=0;
        }
        if(r==0)return "Dire";
        return "Radiant";
    }
};