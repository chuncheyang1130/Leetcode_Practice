class Solution {
public:
    bool permute(string& value, vector<int>& digit, int pos){
        if(pos == value.size()){
            int n = stoi(value);
            if(log2(n) == (int)log2(n))
                return true;
            else return false;
        }
        
        for(int i = 0; i < digit.size(); i++){
            if(pos == 0 && i == 0)
                continue;
            
            if(digit[i]){
                digit[i]--;
                value[pos] = '0'+i;
                bool powerOf2 = permute(value, digit, pos+1);
                if(powerOf2)
                    return true;
                digit[i]++;
            }
        }
        return false;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int> digit(10, 0);
        string value;
        
        while(n > 0){
            int d = n % 10;
            digit[d]++;
            value += " ";
            n /= 10;
        }
        
        return permute(value, digit, 0);
    }
};