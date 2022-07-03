class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if(num1 == "0" || num2 == "0")
            return "0";
        
        // ex. 5 digit number times 4 digit number < 1e9, which is 10 digit => at most 9 digit
        vector<int> result(len1+len2, 0); 
        int carry, n1, n2;
        
        for(int i = len2-1; i >= 0; i--){
            n2 = num2[i] - '0';
            carry = 0;
            for(int j = len1-1; j >= 0; j--){
                n1 = num1[j] - '0';
                int res = n1*n2;
                result[i+j+1] += (res%10) + carry;
                carry = res/10 + result[i+j+1]/10;
                result[i+j+1] %= 10;
            }
            if(carry)
                result[i] += carry;
        }
        
        string ans = "";
        for(int i = 0; i < result.size(); i++){
            if(ans == "" && result[i] == 0)
                continue;
            else ans += '0' + result[i];
        }
        return ans;
    }
};