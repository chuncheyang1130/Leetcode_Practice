class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        
        long long base = 1;
        while(base <= n){
            if(base == n)
                return true;
            base *= 2;
        }
        return false;
    }
};