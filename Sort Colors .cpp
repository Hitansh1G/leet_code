class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0 ; i<nums.size() ; i++){
            pq.push(nums[i]);
        }
        for(int i=0 ; i<nums.size() ; i++){
            nums[i]=pq.top();
            pq.pop();
        }
        
    }
};