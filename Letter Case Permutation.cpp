class Solution {
public:
    vector<string>sol;
    void solve(string curr , string s, int i){
        if(i==s.length()){
            sol.push_back(curr);
            return ;
        }
        if(isdigit(s[i])){
            curr.push_back(s[i]);
            solve(curr,s,i+1);
        }
        else{
            string str = curr;
            str.push_back(tolower(s[i]));
            solve(str,s,i+1);

            string str1 = curr;
            str1.push_back(toupper(s[i]));
            solve(str1,s,i+1);

        }
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        solve("",s,0);
        return sol;
    }
};