class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nu) {
        vector<vector<int>> ans;
        sort(nu.begin(),nu.end());
        int n = nu.size();
        int a;
        for(int i = 0; i<n;i++){
            if(i == 0 || (i>0 && nu[i] != nu[i-1])){
                a = nu[i];
                int low = i+1 , hi = n-1;
                while(low<hi){
                    if(nu[low] + nu[hi] > -a) hi--;
                    else if(nu[low] + nu[hi] < -a) low++;
                    else{
                        ans.push_back({a,nu[low],nu[hi]});
                        while(low<hi && nu[low] == nu[low+1]) low++;
                        while(low<hi && nu[hi] == nu[hi-1]) hi--;
                        low++; hi--;
                    }
                }
            }
        }
        return ans;
    }
};