class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int aiplusi = values[0] + 0;
        int ans = 0;
        int n = values.size();
        
        for(int i=1;i<n;i++){
            ans = max(ans, aiplusi + values[i] - i);
            aiplusi = max(aiplusi, values[i] + i);
        }
        
        return ans;
    }
};