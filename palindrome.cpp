class Solution {
public:
    bool isPalindrome(int x) {
if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0 , temp =0 ;
        while(x > revertedNumber) {
            temp = x%10;
            revertedNumber = revertedNumber * 10 + temp;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber/10;
        
       return 0; 
    }
};