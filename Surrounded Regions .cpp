class Solution {
public:
    
    void computeSafe(int row, int col, vector<vector<char>>& survivors, vector<vector<char>>& board){

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return; 
	
        char state = board[row][col];
        
        if(state == 'O' && survivors[row][col] != 'O'){
            survivors[row][col] = 'O';
            
            computeSafe(row-1, col, survivors, board);
            computeSafe(row+1, col, survivors, board);
            computeSafe(row, col+1, survivors, board);
            computeSafe(row, col-1, survivors, board);
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        int nRow = board.size();
        int nCol = board[0].size(); 
        
        vector<vector<char>> survivors(nRow, vector<char>(nCol, 'X'));
        
        for(int row = 0; row < nRow; row++){
            computeSafe(row, 0, survivors,board);
            computeSafe(row, nCol-1, survivors,board);
        }
        for(int col = 0; col < nCol; col++){
            computeSafe(0, col, survivors,board);
            computeSafe(nRow-1, col, survivors,board);
        }
        
        board = survivors;
    }
};