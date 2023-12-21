class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        vector<std::string> vec;
        string temp = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (!temp.empty()) {
                    vec.push_back(temp);
                    temp = "";
                }
            } else {
                temp += s[i];
            }
        }

        if (!temp.empty()) {
            vec.push_back(temp);
        }

        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }

        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == " ") {
                vec.erase(vec.begin() + i);
                i--; 
            }
        }

        int si = vec.size();
        string som = vec[si - 1];
        return som.size();
    }
};