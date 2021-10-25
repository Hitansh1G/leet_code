class Solution {
public:
    string convert(string s, int r) 
    {        
        if (r == 1)
            return s;
        
        int n = s.length();
        int c = n;
        vector<vector<char>> arr(r, vector<char>(c, '0'));
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        while (k < n) {
            if (i != (r - 1)) {
                while (k < n && i < (r - 1)) {
                    arr[i][j] = s[k];
                    k++;
                    i++;
                }
            }
            else {
                while (k < n && i > 0) {
                    arr[i][j] = s[k];
                    k++;
                    i--;
                    j++;
                }
            }
        }
        
        string result;
        
        for (int l = 0; l < r; l++) {
            for (int m = 0; m < c; m++) {
                if (arr[l][m] != '0') {
                    result += arr[l][m];
                }
            }
        }
        
        return result;
    }
};