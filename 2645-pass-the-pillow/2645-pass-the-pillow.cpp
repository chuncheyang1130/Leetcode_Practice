class Solution {
public:
    int passThePillow(int n, int time) {
        
        int round_time = (n-1) * 2;
        int remain_time = time % round_time;

        if (remain_time <= n-1)
            return remain_time + 1;
        else return n - remain_time % (n-1); 

    }
};