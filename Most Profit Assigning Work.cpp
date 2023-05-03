class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
        priority_queue<pair<int,int>>pq;
        int n=profit.size();
        for(int i=0;i<n;i++){
            pq.push({profit[i],difficulty[i]});
        }
        int ans=0;
        sort(worker.rbegin(),worker.rend());
        for(auto u:worker){
            while(!pq.empty()){
                if(pq.top().second>u)
                    pq.pop();
                else{
                    ans+=pq.top().first;
                    break;
                }
            }
            if(pq.empty())
                break;
        }
        return ans;
    }
};