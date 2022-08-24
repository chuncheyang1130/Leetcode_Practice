class Solution {
public:
    int lengthOfLastWord(string s) {
        int end_pos = s.size()-1;
        while(end_pos >= 0 && s[end_pos] == ' ')
            end_pos--;
        
        if(end_pos == -1)
            return 0;
        
        int start_pos = end_pos;
        while(start_pos >= 0 && s[start_pos] != ' ')
            start_pos--;
        
        return end_pos - start_pos;
    }
};