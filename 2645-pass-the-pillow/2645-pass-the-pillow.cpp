class Solution {
public:
    int passThePillow(int n, int time) {
        
        int remain_time = time % ((n-1) * 2);

        if (remain_time <= n-1)
            return remain_time + 1;
        else return n - remain_time % (n-1); 

    }
};