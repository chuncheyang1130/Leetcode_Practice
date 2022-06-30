class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        
        int M = 0, l = 0;                                                                            
        unordered_map<char,int> table;
        
        for(int i = 0; i < s.size(); i++){
            if(table.find(s[i]) != table.end() && table[s[i]] >= l){
                M = max(M, i - table[s[i]]);
                l = table[s[i]] + 1;
            }else{
                M = max(M, i - l + 1);
            }
            
            table[s[i]] = i;
        }
        
        return M;
    }
};