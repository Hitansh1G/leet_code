class Solution {
public:
    
//     struct comp {
//         template <typename T>

//         // Comparator function
//         bool operator()(const T& l,const T& r) const{
//             if (l.second != r.second) {
//                 return l.second < r.second;
//             }
//             return l.first < r.first;
//         }
//     };
//     void sort(map<int, int>& M){
//         set<pair<int, int>, comp> S(M.begin(), M.end());
//     }

    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        // sort(mp.begin(), mp.end(), cmp);
        // sort(mp);
        int maxi = -1 ;
        int ans=-1;
        // for (auto it = mp.end() ; it != mp.begin() ; --it){
        for(auto it:mp){
            // if(it.first==0){
            //     if(it.second>maxi){
            //         maxi=0;
            //     }
            // }
            if(it.first%2==0 ){
                if(it.second >maxi){
                    maxi = it.second;
                    ans = it.first;
                }
            }
            
                        
            
        }
        
        return ans;
    }
};

//for (auto it = mymap.begin(); it != mymap.end(); ++it)