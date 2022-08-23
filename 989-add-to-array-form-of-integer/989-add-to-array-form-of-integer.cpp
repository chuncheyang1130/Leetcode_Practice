class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> vk, ans;
        
        while(k > 0){
            vk.push_back(k% 10);
            k /= 10;
        }
        reverse(vk.begin(), vk.end());
        
        int len_n = num.size(), len_k = vk.size(), len = max(len_n, len_k);
        int carry = 0;
        int n;
        
        for(int i = 1; i <= len; i++){
            n = carry;
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