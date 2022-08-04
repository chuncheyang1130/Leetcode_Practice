class Solution {
public:
    int mirrorReflection(int p, int q) {
        for(int i = 2; i <= min(p, q); i++){
            while(p % i == 0 && q % i == 0){
                p /= i;
                q /= i;
            }
        }

        if(p % 2 == 0)
            return 2;
        else if(q % 2 == 0)
            return 0;
        else return 1;
    }
};