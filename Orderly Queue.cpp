class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==0){
            return s;
        }
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        if(k==1){
            string st=s;
            for (int i=0;i<s.length()-1;i++){
                string p = s.substr(i+1 , s.length()) + s.substr(0,i+1);
                if(st>p){
                    st=p;
                }
            }
            return st;
        }
        return s;

    }
};