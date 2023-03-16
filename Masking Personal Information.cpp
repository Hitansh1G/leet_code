class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.substr(0, 1) + "*****" + s.substr(s.find('@') - 1);
        }
        else {
            string digits;
            for (char c : s) {
                if (isdigit(c)) {
                    digits.push_back(c);
                }
            }
            string local = "***-***-" + digits.substr(digits.size() - 4);
            if (digits.size() == 10) {
                return local;
            }
            string ans;
            for (int i = 0; i < digits.size() - 10; ++i) {
                ans.push_back('*');
            }
            return "+" + ans + "-" + local;
        }
    }
};