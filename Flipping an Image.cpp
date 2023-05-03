class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        vector<vector<int>>ans(n);
        for (int i=0;i<n;i++){
            for (int j=image[i].size()-1;j>=0;j--)
            {
                int cur=1-image[i][j];
                ans[i].push_back(cur);
            }
        }
        return ans;
    }
};