class Solution {
public:
    int mySqrt(int x) {
        long long int start=1,end=x,ans=0,mid;
        while(start<=end){
            mid=(start+end)/2;
            if((mid*mid)==x) return mid;
            else if((mid*mid)<x){
                // ans=mid;
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return end;
    }
};