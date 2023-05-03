class Solution {
public:
    string simplifyPath(string s) {
        stack<string>st;
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='/') continue;
            string tmp;
            while(i<n && s[i]!='/') 
			  tmp+=s[i++];            
            if(tmp==".") continue;
            else if(tmp==".."){
                  if(!st.empty()) 
                      st.pop();
            }
            else
               st.push(tmp);
        }
        while(!st.empty()){
            ans="/"+ st.top()+ans;
            st.pop();
        }
        
            if(ans.size()==0)return "/";
            
        return ans;
    }
};