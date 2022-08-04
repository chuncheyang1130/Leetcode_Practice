class Solution {
public:
    int mirrorReflection(int p, int q) {
        int n = min(p, q);
        for(int i = 2; i <= n; i++){
            while(p % i == 0 && q % i == 0){
                p /= i;
                q /= i;
            }
        }

        if(p % 2 == 0)
            return 2;
        if(q % 2 == 0)
            return 0;
        return 1;
    }
};