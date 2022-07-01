class Solution {
public:
    int fib(int n) {
        
        if(n <= 1)
            return n;
        
        double phi = ((double)sqrt(5) + 1)/2;
        return round((pow(phi, n) - (pow(-phi+1, n))) / sqrt(5));
    }
};