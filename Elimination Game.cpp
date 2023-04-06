class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)
        return 1;
        int flag =0;
        int a=1,d=1;

        while(n>1){
            if(flag%2==0 || n%2 !=0){    
                a= a+d;
                d = 2*d;
            }
            else{
                d= 2*d;
            }
            n=n/2;
            flag++;
        }
        return a;
    }
};