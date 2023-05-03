class Solution {
public:
    
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = capacity.size();
        int num_of_bags = 0;
        for(int i = 0; i < n; i++){
            if( (capacity[i] - rocks[i]) == 0){
                num_of_bags += 1;
            }
            else{
                pq.push((capacity[i] - rocks[i]));
            }
        }

        while(!pq.empty() && additionalRocks > 0){
            int val = pq.top();
            pq.pop();
            if(val > additionalRocks){
                break;
            }
            additionalRocks -= val;
            val -= val;
            num_of_bags += 1;
        }  
        return num_of_bags;
    }
};