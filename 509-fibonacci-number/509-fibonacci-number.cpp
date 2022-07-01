class Solution {
public:
    int fib(int n) {
        if(n <= 1) 
            return n;
        
        int prev = 0, cur = 1;
        for(int i = 0; i < n-1; i++){
            swap(prev, cur);
            cur += prev;
        }
        return cur;
    }
};