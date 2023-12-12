class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int>s;
        // while(k--){
        //     int temp = nums.back();
        //     nums.pop_back();
        //     nums.insert(nums.begin() + 0, temp); 
        // }
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));
        reverse(nums.begin()+(nums.size()-k),nums.end());
        reverse(nums.begin(),nums.end());
            
    }
};