class Solution {
public:

bool isSubsequence(string s, string t) {
    int n = t.size();
    int j = 0;
    
    for(int i=0; i<n; ++i){
        if(s[j] == t[i]) j++;
    }
    
    return j == s.size() ? true : false;
}
};


