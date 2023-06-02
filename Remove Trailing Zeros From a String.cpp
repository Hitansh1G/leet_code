class Solution {
public:
    string removeTrailingZeros(string num) {
        int n=num.size();
        // str.erase(str.begin() + 4);
        while(num[n-1]=='0'){
            num.erase(num.begin()+n-1);
            n--;
        }
        return num;
    }
};