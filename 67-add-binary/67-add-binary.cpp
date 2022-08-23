class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans;
        
        int len_a = a.size(), len_b = b.size(), len = max(len_a, len_b);
        
        for(int i = 1; i <= len; i++){
            int na = 0, nb = 0, nc = 0;
            if(i <= len_a)
                na = a[len_a - i] == '1';
            if(i <= len_b)
                nb = b[len_b - i] == '1';
            nc = na + nb + carry;
            carry = nc / 2;
            nc = nc % 2;
            if(nc == 1)
                ans.insert(ans.begin(), '1');
            else ans.insert(ans.begin(), '0');
        }
        if(carry)
            ans.insert(ans.begin(), '1');
        
        return ans;
    }
};