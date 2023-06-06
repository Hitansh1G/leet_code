class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr.size()==0)return false;
        if(arr.size()==1 || arr.size()==2)return true;
        int diff = arr[0]-arr[1];
        for(int i=0 ; i<arr.size()-1 ; i++){
            if(arr[i]-arr[i+1]==diff){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};