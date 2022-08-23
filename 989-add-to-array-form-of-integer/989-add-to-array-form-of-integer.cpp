class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> vk, ans;
        
        while(k > 0){
            vk.insert(vk.begin(), k % 10);
            k /= 10;
        }
        
        int len_n = num.size(), len_k = vk.size(), len = max(len_n, len_k);
        int carry = 0;
        
        for(int i = 1; i <= len; i++){
            int n = 0;
            if(i <= len_n)
                n += num[len_n-i];
            if(i <= len_k)
                n += vk[len_k-i];
            
            n += carry;
            carry = n / 10;
            n %= 10;
            ans.insert(ans.begin(), n);
        }
        if(carry)
            ans.insert(ans.begin(), carry);
        return ans;
    }
};