class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // add all the words in a set 
        // iterate every word 
        //find all possible substrings and check if substr is present in the set
        //if yes then remove it
         string ans;
        sort(words.begin(),words.end(),[](string &a,string &b){return a.size() > b.size();});
        for(string &s:words)
            if(ans.find(s + "#") == string::npos) ans += s + "#";
        return ans.size();
    }
};