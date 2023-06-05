class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        if(c.size()==2) return true;
        long double slope = c[1][1]-c[0][1];
        if((c[1][0]-c[0][0])==0){
            for(int i=2;i<c.size();i++){
                if(c[i][0]!=c[1][0]){
                    return false;
                }
            }
            return true;
        }
        else{
            slope = slope/(c[1][0]-c[0][0]);
            long double intersect= c[0][1]-slope*c[0][0];
            for(int i=2;i<c.size();i++){
                if(c[i][1]!=(c[i][0]*slope + intersect)){
                    return false;
                }
            }
            return true;
        }
    }
};