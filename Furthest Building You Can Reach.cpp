class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //if vec[i]>=vec[i+1] {no ladder or brick}
        //else ladder or h[i+1]-h[i]
        //when to use bricks or ladder - sort vec - usme se max ladders niklo and utni ladders baaki bricks
        //So we can take a priority queue for storing the bricks used in each step and so that we can take out the maximum bricks used till a building. We add brick count to the queue whenever we use bricks and take out the max brick whenever we use ladder.
        priority_queue<int> maxB;
        int i=0, diff =0;
        for(i=0 ; i<heights.size()-1 ; i++){
            diff = heights[i+1]-heights[i];
            if(diff<=0) continue;
            bricks -= diff;
            maxB.push(diff);
            if(bricks < 0){
                bricks += maxB.top(); 
                maxB.pop(); 
                ladders--;
            }
            if(ladders < 0) break;
        }
        return i;
        
    }
};