class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int len_n = num.size(), len_k = (int)log10(k)+1, len = max(len_n, len_k);
        int carry = 0;
        
        for(int i = 1; i <= len; i++){
            int n = carry;
            if(i <= len_n)
                n += num[len_n-i];
            if(k > 0){
                n += (k % 10);
                k /= 10;
            }
            
            carry = n / 10;
            n %= 10;
            ans.insert(ans.begin(), n);
        }
        if(carry)
            ans.insert(ans.begin(), carry);
        return ans;
    }
};