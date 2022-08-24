class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return 0;
            return pow(3, (int)(log2(n) * 1.0 /log2(3))) == n;
    }
};