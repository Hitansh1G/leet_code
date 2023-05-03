class Solution {
public:
    bool isHappy(int n) {
        long long fin=0;
        while(fin!=1 and n!=1){
            if((n>=2 and n<=6) || (n==8 || n==9)) return false;
            if(n==7) return true;
            while(n!=0){
                long long rem = n%10;
                fin += rem*rem ;
                n=n/10;
                cout<<fin<<endl;                
            }
            n=fin;
            fin=0;
        }
        return true;
    }
};