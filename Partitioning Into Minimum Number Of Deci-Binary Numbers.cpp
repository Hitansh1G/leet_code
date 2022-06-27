class Solution {
public:
    int minPartitions(string str) {
        int n = str.size();
        int maxi=0;
        for(auto it : str){
            int dig = it-'0';
            maxi = max(maxi,dig);
        }
        return maxi;
    }
};