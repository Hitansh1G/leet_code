class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        int x[8]={-1,-1,-1,0,0,1,1,1};
        int y[8]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]*=3;                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live=0,dead=0;
                for(int k=0;k<8;k++){
                    if(i+x[k]>=0&&j+y[k]>=0&&i+x[k]<n&&j+y[k]<m){
                        if(board[i+x[k]][j+y[k]]/3)
                            live++;
                        else
                            dead++;
                    }
                }
                if(board[i][j]/3==1){
                    if(live<2||live>3){
                        board[i][j]+=0;
                    }
                    else if(live==2||live==3){
                        board[i][j]+=1;
                    }
                }
                else{
                    if(live==3){
                        board[i][j]+=1;
                    }
                }
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=board[i][j]%3;                
            }
        }
    }
};