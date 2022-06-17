class Solution {
public:
    int reverse(int num) {
        int x=0;
        while (num) {
            if (x>INT_MAX/10||x==INT_MAX&&num%10>7) return 0;
            if (x<INT_MIN/10||x==INT_MIN&&num%10<-8) return 0;
            x=10*x+num%10;
            num/=10;
        }
        return x;
    }
};