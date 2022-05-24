class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        int min_val = arr[0];
        for(int i = 1; i < n; i++){
            int diff = arr[i] - min_val;
            maxi = max(maxi, diff);   
            min_val = min(min_val, arr[i]);
        }   
        return maxi;
    }
        
};

