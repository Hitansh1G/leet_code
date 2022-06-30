class Solution {
public:
    string intToRoman(int num) {
        string s;
        unordered_map<int,char> m{{1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}};
        int n=100,a=num,i;
        if(a/1000>0){
            for(i=0;i<a/1000;i++)
                s.push_back(m[1000]);
            a=a%1000;
        }
        while(a>0){
            if(a/(9*n)==1){
                s.push_back(m[n]);
                s.push_back(m[n*10]);
            }
            else if(a/(5*n)>0){
                s.push_back(m[5*n]);
                for(i=0;i<(a/n)-5;i++)
                    s.push_back(m[n]);
            }
            else if(a/(4*n)==1){
                s.push_back(m[n]);
                s.push_back(m[n*5]);
            }
            else if(a/(n)>0)
                for(i=0;i<a/n;i++)
                    s.push_back(m[n]);
            a%=n;
            n/=10;
        }
        return s;
    }
};