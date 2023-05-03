class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts){
        int dx = startPos[0] <= homePos[0] ? 1  : -1;
        int dy = startPos[1] <= homePos[1] ? 1  : -1;
        long total_cost = 0;
        for(int row = startPos[0]; row != homePos[0]; row += dx)
            total_cost += rowCosts[row + dx]; 
        
        for(int col = startPos[1]; col != homePos[1]; col += dy)
            total_cost += colCosts[col + dy]; 
            
        return total_cost;
    }
};