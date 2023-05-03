class Solution {
public:
    string makeGood(string s) {
        string res="";
        for(auto x:s){
            if(res.size()!=0){
                char temp= res.back();
                char temp1= x;
                if((temp-'a'== temp1-'A') or(temp-'A'== temp1-'a')) res.pop_back();
                else res+=x;
            }
            else res+=x;
        }
        return res;
    }
};