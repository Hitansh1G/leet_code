class Solution
{
public:
    int divide(int dividend, int divisor){
        // edge cases
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) return 1;
            else return 0;
        }

        bool negative = (dividend < 0) ^ (divisor < 0); // XOR
        if (divisor < 0) divisor = -divisor;
        int overflow = 0;
        if(dividend == INT_MIN) {
            dividend = INT_MAX;
            overflow = 1;
        } else if(dividend < 0){
            dividend = -dividend;
        }

        int quotient = 0;
        while (dividend >= divisor) {
            pair<int, int> result = divide_step(dividend, divisor, overflow);
            quotient += result.first;
            dividend = result.second;
        }
        if (dividend + overflow == divisor) quotient++;
        
        return negative ? -quotient : quotient;
    }

    pair<int, int> divide_step(int dividend, int divisor, int overflow){
        if (dividend < divisor) return {0, dividend};

        int quotient = 1; // range: [1, 2147483647]
        int sum = divisor;
        while (sum < (INT_MAX << 1) && sum + sum <= dividend) {
            quotient += quotient;
            sum += sum;
        }

        return {quotient, dividend - sum};
    }
};