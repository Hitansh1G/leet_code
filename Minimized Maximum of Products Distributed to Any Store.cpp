class Solution {
public:
    bool check(int n, vector<int>& qty, int currans){
        for(int i=0; i<qty.size(); i++){
            if(n<=0)
                return false;
            int t=qty[i];
            while(n>0 && t>=currans){
                t=t-currans;
                n--;
            }
            if(t>0 && n>0){
                t=0;
                n--;
            }
            else if(t>0 && n<=0)
                return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& qty) {
        int low=0;
        int high=*max_element(qty.begin(), qty.end());

        int result;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(n, qty, mid)){
                result=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }

        return result;
    }
};