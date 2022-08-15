class Solution {
public:
    unordered_map<char, int> table = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };
    
    int romanToInt(string s) {
        int value = table[s[s.size()-1]];

        for(int i = s.size()-2; i >= 0; i--){
            if(table[s[i]] < table[s[i+1]])
                value -= table[s[i]];
            else    
                value += table[s[i]];
        }
        
        return value;
    }
};