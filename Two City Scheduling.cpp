class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> sol;
        int N = costs.size()/2;
        int minCost = 0;
        for(vector<int> cost : costs){
            minCost += cost[0];
            sol.push_back(cost[1] - cost[0]); 
        }
        sort(sol.begin(), sol.end());
        for(int i = 0; i < N; i++){
            minCost += sol[i];
        }
        return minCost;
    }
};