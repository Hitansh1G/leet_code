class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l=-1,r=m*n+1;
        while(l+1<r){
            int mid=(l+r)/2;
            int count=0;
            for(int i=1;i<=m;i++){
                count+=(mid/i)>n?n:(mid/i);
            }
            if(count>=k) r=mid;
            else l=mid;
        }
        return r;
    }
};