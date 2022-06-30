class Solution {
public:
    int reverse(int x) {
        string num = to_string(x);
        std::reverse(num.begin(), num.end());
        
        if(num.back() == '-')
            num = "-" + num.substr(0, num.size()-1);
        
        long long value = stoll(num, nullptr, 10);
        if(value < INT_MIN || value > INT_MAX)
            return 0;
        else return (int)value;
        
    }
};