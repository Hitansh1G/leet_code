class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int>s;
        for(int i=0 ; i<20 ; i++){
            long long int ans = pow(x,i);
            if(ans >= bound) 
                break;
            for(int j=0 ; j<20 ; j++){
                long long sol = pow(y,j);
                if(ans + sol > bound){
                    break;
                }
                else s.insert(ans + sol);
            }
        }
        vector<int>total(s.begin() , s.end());
        return total;
    }
};