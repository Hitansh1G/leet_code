class Solution {
public:
    int countAsterisks(string s) {
        int n = s.size();
        int countofl=0;
        int sum=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='|'){
                countofl++;
            }
            if(countofl%2==0){
                if(s[i]=='*'){
                    sum++;
                }
            }
        }
        if(sum==0){
            sum=0;
        }
        return sum;
    }
};