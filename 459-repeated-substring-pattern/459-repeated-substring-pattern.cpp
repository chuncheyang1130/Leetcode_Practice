class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i < s.size(); i++){
            if(s.size() % i > 0)
                continue;
            string str = s.substr(0, i);
            bool pattern = true;
            for(int j = i; j < s.size(); j += i){
                if(str != s.substr(j, i)){
                    pattern = false;
                    break;
                }
            }
            if(pattern)
                return true;
        }
        return false;
    }
};