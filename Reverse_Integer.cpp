//all usual stuff
class Solution {
public:
    int reverse(int x) {
        int temp=0, rev =0, pop;
        while(x!=0){
            pop = x % 10;
            x = x / 10;
            temp = rev * 10 + pop;
            rev = temp;}
        
            return rev;
        
        return 0;
     
        }

    
};