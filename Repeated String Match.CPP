class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int c = 1;
        while(a.size() < b.size()){
            a += temp;
            c++;
        }
        if(a.find(b) != -1) 
            return c;
        a += temp ;
        c++;
        if(a.find(b) != -1) 
            return c;
        return -1;
    }
};