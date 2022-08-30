class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = false;
        if( (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ){
            neg = true;
            if(dividend < 0)
                dividend = abs(dividend);
            else divisor = abs(divisor);
        }
        
        long long quotient = (long long)dividend / divisor;
        if(neg && -quotient < INT_MIN)
            quotient = INT_MIN;
        else if(neg)
            quotient *= -1;
        else if(!neg && quotient > INT_MAX)
            quotient = INT_MAX;
        
        return quotient;
    }
};