class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int>frq;
        for(int i=0;i<n;i++)
            frq[s[i]]++;             
        int cnt=0;
        int flag=0;
        for(int i=0;i<n;i++){
            if(frq[s[i]]%2==0 ){       
                cnt+=frq[s[i]];
                frq[s[i]]=0;
            }else if(frq[s[i]]>2){       
                cnt+=frq[s[i]]-frq[s[i]]%2;
                frq[s[i]]=1;
            }
            else
                flag=1;     
        }
        if(flag==0)
                return cnt;
        else 
            return cnt+1;
    }
};