class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length())return false;
        map<char , int>ref;
        for(int i = 0 ; i  <s.length(); i++){
            ref[s[i]]++;
        }
        for(int i = 0 ; i  < t.length() ; i++){
            if(ref[t[i]] >0){
                ref[t[i]]--;
            }else{
                return false;
            }
        }
        return true;
    }
};