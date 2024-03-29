class Solution {
public:
    void bfs(int prevcolor,int row,int col,int color,vector<vector<int>>&visited,vector<vector<int>>&image){
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=1;

        while(!q.empty()){
            row = q.front().first;
            col = q.front().second;
            q.pop();
            if(image[row][col]==prevcolor) image[row][col]=color;

            // up
            if(row-1>=0 && !visited[row-1][col] && image[row-1][col]==prevcolor) q.push({row-1,col}),visited[row-1][col]=1, image[row-1][col]=color;

            // right
            if(col+1<image[0].size() &&  !visited[row][col+1] && image[row][col+1]==prevcolor) q.push({row,col+1}),visited[row][col+1]=1, image[row][col+1]=color;

            //down
            if(row+1<image.size() && !visited[row+1][col] && image[row+1][col]==prevcolor) q.push({row+1,col}),visited[row+1][col]=1, image[row+1][col]=color;

            // left
            if(col-1>=0 && !visited[row][col-1] && image[row][col-1]==prevcolor) q.push({row,col-1}),visited[row][col-1]=1, image[row][col-1]=color;
        }
    }


    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int prevcolor = image[sr][sc];

          vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));

          bfs(prevcolor,sr,sc,color,visited,image);

          return image;
    }
};