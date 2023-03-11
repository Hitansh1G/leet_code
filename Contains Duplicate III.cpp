class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        // long long n=nums.size();
        // // sort(nums.begin() , nums.end());
        // for( long long i=0 ; i<n-1 ; i++){
        //     for(long long j=i+1 ; j<n ; j++){
        //         if(abs(i - j) <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        vector<pair<long,long>> vec(nums.size());
        for(int i = 0 ; i < nums.size() ; i++){
            vec[i].first = nums[i];
            vec[i].second = i;
        }
        sort(vec.begin(),vec.end());
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                if(abs(vec[i].first + valueDiff >= vec[j].first)){  
                    if(abs(vec[i].second - vec[j].second) <= indexDiff)
                        return true;
                }
                else
                    break;
            }
        }
        return false;
    }
    
};