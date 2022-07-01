class Solution {
public:
    int fib(int n) {
        
        if(n <= 1)
            return n;
        
        int two_num_prev = 0, prev = 1, cur;
        for(int i = 0; i < n-1; i++){
            cur = two_num_prev + prev;
            two_num_prev = prev;
            prev = cur;
        }
        return prev;
    }
};