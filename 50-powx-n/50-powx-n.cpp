class Solution {
public:
    double myPow(double x, int n) {
        double base = x, ans = 1.0;
        bool neg = false;
        long long num = n;
        
        if(num < 0){
            num = -num;
            neg = true;
        }
        
        while(num > 0){
            if(num % 2)
                ans *= x;
            num /= 2;
            x *= x;
        }
        
        if(neg)
            ans = 1.0/ans;
        return ans;
    }
};