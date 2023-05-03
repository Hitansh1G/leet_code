class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        vector<int>temp;
		//base case
        if(rows==1 && cols==1){
            temp.push_back(0);
            temp.push_back(0);
            ans.push_back(temp);
            return ans;
        }
        int steps=1;
        int n=2;
        int size=0;
        int x=rStart,y=cStart;
		
		//for tracking the direction
        char dir='r';
		
		//for first step
        temp.push_back(x);
        temp.push_back(y);
        ans.push_back(temp);
        size++;
        temp.clear();
        while(size<=cols*rows){
            for(int i=0;i<n;i++){
                for(int j=0;j<steps;j++){
                    if(dir=='r')y++;
                    else if(dir=='b')x++;
                    else if(dir=='l')y--;
                    else if(dir=='u')x--;
                    if(x>=0 && x<rows && y>=0 && y<cols){
                        temp.push_back(x);
                        temp.push_back(y);
                        ans.push_back(temp);
                        temp.clear();
                        size++;
                        if(size==cols*rows)
                            return ans;
                    }
                }
                if(dir=='r')dir='b';
                else if(dir=='b')dir='l';
                else if(dir=='l')dir='u';
                else if(dir=='u')dir='r';
            }
			//after two iterations in 2 directions we need to change the number of steps
            steps++;
        }
        return ans;
    }
};