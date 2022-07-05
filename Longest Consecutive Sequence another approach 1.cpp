class Solution {  
    unordered_map<int,int>par; 
    int findpar(int n){  
        if(par.count(n)==0) return n ; 
        return par[n]=findpar(par[n]);
    }
    void Union(int a,int b){  
        a=findpar(a); 
        b=findpar(b); 
        par[b]=a;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp; 
        int ans=0;
        for(int i:nums){ 
            int curr=findpar(i);
            if(mp.count(curr)) continue; 
            int prev=findpar(i-1);
            int next=findpar(i+1);   
            mp[curr]=1;
            if(mp.count(prev)){ 
                mp[curr]+=mp[prev];
                Union(curr,prev);       
            } 
            if(mp.count(next)){ 
                mp[curr]+=mp[next]; 
                Union(curr,next); 
            }      
            ans=max(ans,mp[curr]);    
        } 
        return ans;
    }
};