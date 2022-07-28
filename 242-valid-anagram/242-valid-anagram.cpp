class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> table;
        if(s.size() != t.size())
            return false;
        
        for(int i = 0; i < s.size(); i++){
            table[s[i]]++;
            table[t[i]]--;
        }
        
        for(auto it = table.begin(); it != table.end(); it++){
            if(it->second != 0)
                return false;
        }
        return true;
    }
};