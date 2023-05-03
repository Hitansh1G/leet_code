class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>v1(26);
        vector<int>v2;
        for(int i=0;i<chars.size();i++){
            v1[chars[i]-'a']++;
        }
        v2=v1;
        int ans=0;
        for(int i=0 ; i<words.size() ; i++){
            string s = words[i];
            bool l = true;
            for(int j=0 ; j<s.size() ; j++){
                if(v1[s[j]-'a']==0){
                    l = false;
                    break;
                }
                else{
                    v1[s[j]-'a']--;
                }
            }
            if(l==true){
                ans+=s.size();
            }
            v1=v2;
        }
        return ans;
    }
};