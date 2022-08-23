class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> vk, ans;
        
        while(k > 0){
            int n = k % 10;
            vk.insert(vk.begin(), n);
            k /= 10;
        }
        
        int len_n = num.size(), len_k = vk.size(), len = max(len_n, len_k);
        int carry = 0;
        
        for(int i = 1; i <= len; i++){
            int n = carry;
            if(i <= len_n)
                n += num[len_n-i];
            if(i <= len_k)
                n += vk[len_k-i];
            
            carry = n / 10;
            ans.insert(ans.begin(), n % 10);
        }
        if(carry)
            ans.insert(ans.begin(), carry);
        return ans;
    }
};