class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int l = 1; l <= n/2; l++) {
            if (composable(s, l, n)) return true;
        }
        return false;
    }
    bool composable(string& s, int len, int n) {
        if (n % len != 0) return false; 
        int quotient = n / len;
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < quotient; j++) {
                if (s[j*len + i] != s[i]) return false;
            }
        }
        return true;
    }
};