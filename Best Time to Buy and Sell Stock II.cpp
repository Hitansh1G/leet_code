class Solution {
public:
    int maxProfit(vector<int>& vec) {
        int n = vec.size();
        int profit = 0;
        for(int i=0 ; i<n-1 ; i++){
            if(vec[i+1]>vec[i])
                profit += vec[i+1] - vec[i];
        }
        return profit;
    }
};