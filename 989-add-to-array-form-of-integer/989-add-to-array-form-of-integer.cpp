class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int len_n = num.size();
        int len_k = (int)log10(k) + 1;
        int len = max(len_n, len_k);
        int carry = 0;
        
        vector<int> ans(len, 0);
        
        for(int i = 1; i <= len; i++){
            ans[len-i] = carry;
            if(i <= len_n)
                ans[len-i] += num[len_n-i];
            if(k > 0){
                ans[len-i] += (k % 10);
                k /= 10;
            }
            
            carry = ans[len-i] / 10;
            ans[len-i] %= 10;
        }
        
        if(carry)
            ans.insert(ans.begin(), carry);
        return ans;
    }
};