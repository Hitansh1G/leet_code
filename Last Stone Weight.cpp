class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        if(stones.size()==1){
            return stones[0];
        }
        
        for(int i=0 ; i<stones.size() ; i++){
            pq.push(stones[i]);
        }
        while(pq.size()>0){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y){
                pq.push(x-y);
            }
            if(pq.size()==1){
                return pq.top();
            }
        }
        return 0;
    }
};