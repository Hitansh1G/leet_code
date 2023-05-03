class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        //make a substring of the given query
        //traverse kro usme and count no of plates
        // vector<int>ans;
        vector<int>ans(q.size(),0);
        vector<int>v;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='|')v.push_back(i);
        }
        vector<int>::iterator x, y;
        for(int i=0 ; i<q.size() ; i++){
            x = lower_bound(v.begin(),v.end(),q[i][0]);
            y=lower_bound(v.begin(),v.end(),q[i][1]);
            if(v.size()==0)break;
            if(y==v.end())y--;
			else if(*y!=q[i][1])y--;
			if(x==v.end()|| x>=y)continue;    
			ans[i]=(*y-*x-1-(y-x-1));
        }
        
        return ans;
    }
};