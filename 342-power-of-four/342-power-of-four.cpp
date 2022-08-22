class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0)
            return false;

        if(log(n)/log(4) == floor(log(n)/log(4)))
            return true;
        else return false;
    }
};