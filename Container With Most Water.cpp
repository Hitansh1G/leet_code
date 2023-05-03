class Solution {
public:
    int maxArea(vector<int>& vec) {
        int l=0;
        int r=vec.size()-1;
        int area=0;
        while(l<r){
            area = max(min(vec[l],vec[r])*(r-l),area);
            if(vec[l]<vec[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return area;
    }
};