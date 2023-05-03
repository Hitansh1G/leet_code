class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)
            return 0;
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n==-1)
            return 1/x;
        if(n%2==0){
            double e = myPow(x,n/2);
            return e*e;
        }
        else{
            double e = myPow(x,n/2);
            return e*e*myPow(x,n-(n/2+n/2));
        }
    }
};