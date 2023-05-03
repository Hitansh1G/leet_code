class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> p(m+1, vector<int> (n+1, 0));
        
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) 
                p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i-1][j-1];
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                int r = i+1, c = j+1;
                int minRow = max(r-k, 1), minCol = max(c-k, 1), maxRow = min(r+k, m), maxCol = min(c+k, n);
                
                a[i][j] = p[maxRow][maxCol] - p[maxRow][minCol-1] - p[minRow-1][maxCol] + p[minRow-1][minCol-1];
            }
        
        
        return a;
                
    }
};