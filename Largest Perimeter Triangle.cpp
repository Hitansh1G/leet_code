class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int i = n-1;
        while(i>=2){
            int l1 = arr[i];
            int l2 = arr[i-1];
            int l3 = arr[i-2];
            if(l1 < l2 + l3) return l1 + l2 + l3;
            i--;
        }
        return 0;
        
    }
};