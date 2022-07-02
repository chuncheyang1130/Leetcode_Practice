class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_table, t_table;
        for(int i = 0; i < s.size(); i++){
            if(s_table.find(s[i]) != s_table.end()){
                if(t[i] != s_table[s[i]])
                    return false;
            }else if(t_table.find(t[i]) != t_table.end()){
                return false;
            }else{
                s_table[s[i]] = t[i];
                t_table[t[i]] = s[i];
            }
        }
        return true;
    }
};