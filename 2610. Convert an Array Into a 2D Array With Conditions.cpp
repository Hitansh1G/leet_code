class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_set<int>s; // to check when to start new row
        while(nums.empty() == false){
            vector<int>new_row;
            for(int i=0;i<nums.size();i++){
                if(s.find(nums[i]) == s.end()){
                    new_row.push_back(nums[i]);
                    s.insert(nums[i]);
                    nums.erase(nums.begin()+i); 
                    i--;
                }
            }
            ans.push_back(new_row);
            s.clear();
        }
        return ans;
        
    }
};