class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
            return -1;
        
        string str = haystack.substr(0, needle.size());
        if(str == needle)
            return 0;
        
        str.erase(str.begin());
        
        for(int i = needle.size(); i < haystack.size(); i++){
            str += haystack[i];
            if(str == needle)
                return i - needle.size() + 1;
            else str.erase(str.begin());
        }
        return -1;
    }
};