class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        for (int i = 0, j = 0; i < n && j < m; ++i, ++j) {
            while (j < m && s[j] < g[i]) {
                ++j;
            }
            if (j < m) {
                ++count;
            }
        }

        return count;
    }
};