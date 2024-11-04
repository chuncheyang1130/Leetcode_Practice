class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() == 1)
            return s;
            
        string new_str = "";
        new_str.push_back(s[0]);

        for (int i = 1; i < s.size()-1; i++){
            if (s[i+1] != s[i] || s[i] != s[i-1])
                new_str.push_back(s[i]);
        }

        new_str.push_back(s.back());

        return new_str;
    }
};