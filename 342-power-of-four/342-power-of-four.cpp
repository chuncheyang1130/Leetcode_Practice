class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0)
            return false;
        double power = log(n)/log(4);
        if(power == floor(power))
            return true;
        else return false;
    }
};