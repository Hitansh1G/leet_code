class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>vec;
        for(int i=0 ; i<points.size(); i++){
            vec.push_back(points[i][0]);
        }
        sort(vec.begin(),vec.end());
        int maxi=INT_MIN;
        for(int i=0 ;i<vec.size()-1;i++){
            maxi = max(maxi , vec[i+1]-vec[i]);
        }
        return maxi;
    }
};