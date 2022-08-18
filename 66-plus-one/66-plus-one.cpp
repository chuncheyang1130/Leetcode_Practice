class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool add = true;
        
        for(int i = digits.size()-1; i >= 0; i--){
            if(add)
                digits[i]++;
            else break;
            
            if(digits[i] / 10){
                digits[i] = 0;
                add = true;
            }else add = false;
        }
        
        if(add)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};