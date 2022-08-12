class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0)
            return 0;
        int ind = 0;
        bool neg = false;
        
        while(s[ind] == ' ')
            ind++;
        if(s[ind] == '-' || s[ind] == '+'){
            if(s[ind] == '-')
                neg = true;
            ind++;
        }
        
        while(s[ind] == '0')
            ind++;
        
        int l = ind;
        int r = ind;
        while(s[r] <= '9' && s[r] >= '0')
            r++;
        
        long long number = 0;
        long long base = 1;
        r--;
        
        for(int i = r; i >= l; i--){
            number += base * (s[i] - '0');
            if(base != (long long)1e18)
                base *= 10;
            
            if((!neg && number > INT_MAX) || (i != l && base == (long long)1e18))
                return INT_MAX;
            else if((neg && -number < INT_MIN) || (i != l && base == (long long)1e18))
                return INT_MIN;
        }
        
        if(neg)
            return -number;
        return number;
    }
};