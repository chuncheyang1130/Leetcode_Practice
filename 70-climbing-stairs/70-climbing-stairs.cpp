class Solution {
public:
    int climbStairs(int n) {
        
        int prev = 0, cur = 1;
        for(int i = 0; i < n; i++){
            swap(cur, prev);
            cur += prev;
        }
        return cur;
    }
};