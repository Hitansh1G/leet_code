class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>s;
        while(k--){
            int temp = nums.back();
            nums.pop_back();
            nums.insert(nums.begin() + 0, temp); 
        }
    }
};