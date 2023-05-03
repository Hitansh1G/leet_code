class Solution {
public:
    vector<string> ans;
    vector<vector<char>> a;
    string s = "";
    void f(string dig, int l){
        if(dig.size() == s.size()){
            ans.push_back(s);
            return;
        }
        for(int i = 0; i < a[dig[l]-'0'].size(); i++){
            s += a[dig[l]-'0'][i];
            f(dig, l+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        a = vector<vector<char>>(10);
    a[2] = {'a', 'b', 'c'};
    a[3] = {'d', 'e', 'f'};
    a[4] = {'g', 'h', 'i'};
    a[5] = {'j', 'k', 'l'};
    a[6] = {'m', 'n', 'o'};
    a[7] = {'p', 'q', 'r', 's'};
    a[8] = {'t', 'u', 'v'};
    a[9] = {'w', 'x', 'y', 'z'};
        f(digits, 0);
        return ans;
    }
};