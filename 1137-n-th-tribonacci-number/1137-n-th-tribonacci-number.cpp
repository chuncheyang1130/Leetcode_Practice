class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1)
            return n;
        int two_num_prev = 0, prev = 1, cur = 1;
        for(int i = 0; i < n-2; i++){
            swap(two_num_prev, cur);
            cur += two_num_prev + prev;
            swap(prev, two_num_prev);
        }
        return cur;
    }
};