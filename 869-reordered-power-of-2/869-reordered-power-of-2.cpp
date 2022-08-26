class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> digit(10, 0);
        int tmp_num = n;
        while(tmp_num > 0){
            int d = tmp_num % 10;
            digit[d]++;
            tmp_num /= 10;
        }
        
        long long base = 1;
        while(floor(log10(base))+1 < floor(log10(n))+1)
            base *= 2;
        
        while(floor(log10(base))+1 == floor(log10(n))+1){
            vector<int> tmp = digit;
            long long tmp_n = base;
            bool match = true;
            while(tmp_n > 0){
                int d = tmp_n % 10;
                if(tmp[d] == 0){
                    match = false;
                    break;
                }else tmp[d]--;
                
                tmp_n /= 10;
            }
            if(match)
                return true;
            base *= 2;
        }
        return false;
        
    }
};