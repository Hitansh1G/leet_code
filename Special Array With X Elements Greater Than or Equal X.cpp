class Solution {
public:
    int specialArray(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size(),max=arr[n-1];
        for(int i=1;i<=n;i++){
            int idx=lower_bound(arr.begin(),arr.end(),i)-arr.begin();
            if(n-idx==i){
                return i;
            }
        }return -1;
    }
};