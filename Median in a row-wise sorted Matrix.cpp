class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        vector<int> ans;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()/2];
    }
};