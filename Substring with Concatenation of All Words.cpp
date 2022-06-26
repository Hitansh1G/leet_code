class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int fl = words[0].length();
        int tl=fl*words.size();
        
        int n=s.length();
        if(tl>n) return ans;
        
        map<string,int> m;
        for(int i=0;i<words.size();i++){
            if(m.find(words[i])!=m.end()) m[words[i]]+=1;
            else m[words[i]]=1;
        }

        for(int i=0;i<=(n-tl);i++){
            string temp="";
            map<string,int> wc=m;
            for(int j=i;j<n;j+=fl){
                temp=s.substr(j,fl);
                if(wc.find(temp)!=wc.end()){
                    if(wc[temp]==1){
                        wc.erase(temp);
                    }
                    else{
                        wc[temp]-=1;
                    }
                    int stind=(j+fl)-tl;
                    if(wc.size()==0)
                        ans.push_back(stind);
                 }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};