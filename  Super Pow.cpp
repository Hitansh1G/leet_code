class Solution {
public:
    const int mod=1337;
    int sol (int l , int h ,int a){
        if(l>= h ){
            return a%mod;
        }
        int mid = (h+l)/2;
        int lv = sol(l,mid,a);
        int hv = sol(mid+1,h,a);
        return (lv*hv)%mod;
    }
    int superPow(int a, vector<int>& b) {
        int pow = 0; 
        int bmod = 0;
        for(int val:b){
            bmod = (bmod*10+val)%1140;
        }
        return sol(1,bmod,a);
    }
};