class Solution {
public:
    
    bool isFascinating(int n) {
        string str = to_string(n) + to_string(2*n) + to_string(n*3);
        int vec[10] = {0};

        for (int i = 0; i < str.length(); i++) {
            vec[str[i] - '0']++;
        }


        for (int i = 1; i <= 9; i++) {
            if (vec[i] != 1 || str.find('0') != string::npos) {
              return false;
            }
        }
        return true;
        
    }
};