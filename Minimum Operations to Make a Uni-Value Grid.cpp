class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int median = arr[size / 2];
        int count = 0;
        for(int i = 0; i < size; i++){
            if(abs(median - arr[i]) % x)
                return -1;
            else
                count += abs(median - arr[i]) / x;
            
        }      
        return count;
    }
};