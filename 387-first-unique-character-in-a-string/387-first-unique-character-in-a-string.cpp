class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> table(26, (int)1e6);
        for(int i = 0; i < s.size(); i++){
            if(table[s[i]-'a'] == (int)1e6)
                table[s[i]-'a'] = i;
            else if(table[s[i]-'a'] != INT_MAX)
                table[s[i]-'a'] = INT_MAX;
        }
        
        int m = (int)1e6;
        for(int i = 0; i < 26; i++)
            m = min(m, table[i]);
        if(m == (int)1e6)
            return -1;
        return m;
    }
}; 