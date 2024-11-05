class Solution {
public:
    int minChanges(string s) {
        int len = s.size();
        int step = 0;

        for (int i = 0; i < len/2; i++){
            if (s[i*2] != s[i*2+1])
                step++;
        }

        return step;
    }
};