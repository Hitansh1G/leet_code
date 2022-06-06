class Solution {
public:
    string removeDigit(string str, char dig) {
        vector<int>vec;
        // for(int i=0 ; i<str.size() ; i++){
        //     if(str[i] == dig ){
        //         vec.push_back(i);
        //     }
        // }
        string ans="";
        // int index = -1;
        // for(int i=0 ; i<vec.size() ; i++){
        //     if(i<str.size()-2 && str[vec[i]] < vec[str[i]+1]){
        //         index = vec[i];
        //     }
        // }
        for(int i=0 ; i<str.size() ; i++){
            if(str[i]==dig){
                ans = max(ans,str.substr(0,i) + str.substr(i+1,str.size()-1));
            }
        }
        return ans;
    }
};