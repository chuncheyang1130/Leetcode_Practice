class Solution {
public:
    string makeFancyString(string s) {
        int len = s.size();

        for (int i = len-2; i >= 1; i--){
            if (s[i+1] == s[i] && s[i] == s[i-1])
                s.erase(s.begin()+i);
        }
        return s;
    }
};