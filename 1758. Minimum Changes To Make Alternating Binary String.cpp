class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if((i & 1) == 0 and s[i] == '1') count++;
            if((i & 1) == 1 and s[i] == '0') count++;
        }

        return min(count, n - count); 
    }
};