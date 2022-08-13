class Solution {
public:
	string minWindow(string s, string t) {
		int n = t.size();
		if(s.size()<n)  return "";
		unordered_map<int,int>mp;
		for(int i=0;i<n;i++)    
            mp[t[i]]++;
		int count = mp.size(), i=0,j=0, len = INT_MAX;
		n = s.size();
		string ans;
		while(j<n){
			if(mp.find(s[j])!=mp.end()){
				mp[s[j]]--;
				if(mp[s[j]]==0)    count--;
			}
			if(count==0){
				if(len > j-i+1){
					len = j-i+1;
					ans = s.substr(i,len);
				}
				while(count == 0 && i<=j){
					if(mp.find(s[i])!=mp.end()){
						mp[s[i]]++;
						if(mp[s[i]]==1) {
							if(len > j-i+1)
							{
								len = j-i+1;
								ans = s.substr(i,len);
							}
							count++;
						}
					}
					i++;
				}  
			}                      
			j++;
		}
		return ans;
		}
};