class Solution {
public:
       bool dfs(vector<vector<char>>& board, string word, vector<vector<int>> &vis, int i , int j, int m , int n, int idx)
    {
        if(idx == word.length()) return 1;
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(board[i][j]!=word[idx]) return 0;
        if(vis[i][j]) return 0;
        vis[i][j]=1;
        bool val = dfs(board, word, vis, i+1, j, m, n, idx+1) ||
            dfs(board, word, vis, i-1, j, m, n, idx+1) ||
            dfs(board, word, vis, i, j+1, m, n, idx+1) ||
            dfs(board, word, vis, i, j-1, m, n, idx+1);
        vis[i][j]=0;
        return val;
    }
    bool exist(vector<vector<char>>& board, string word) {
       int m = board.size();
       int n = board[0].size();
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
              if(board[i][j] == word[0])
              {
                  vector<vector<int>> vis(m, vector<int> (n, 0));
                  if(dfs(board, word, vis, i, j, m, n, 0)) return 1;
              }
           }
       }
        return 0;
    }
};