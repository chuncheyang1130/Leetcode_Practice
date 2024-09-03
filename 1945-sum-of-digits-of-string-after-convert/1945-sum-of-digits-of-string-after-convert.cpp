class Solution {
public:
    int getLucky(string s, int k) {

        string convert;

        for (int i = s.size()-1; i >= 0; i--) {
            int n = s[i] - 'a' + 1;

            while (n / 10) {
                convert.insert(convert.begin(), '0'+n%10);
                n /= 10;
            }
            
            if (n != 0)
                convert.insert(convert.begin(), '0'+n);
        }
        
        int total = 0;
        while (k--){
            for (int i = convert.size()-1; i >= 0; i--)
                total += convert[i] - '0';
            
            if (k == 0)
                break;
            
            convert = "";
            while (total / 10){
                convert.insert(convert.begin(), '0'+total%10);
                total /= 10;
            }

            if (total != 0)
                convert.insert(convert.begin(), '0'+total);

            total = 0;
        }
        

        return total;
    }
};