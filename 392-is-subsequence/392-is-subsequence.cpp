class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto sp = s.begin(), tp = t.begin();
        
        while(tp != t.end()){
            if(sp == s.end())
                return true;
            else{
                if(*sp == *tp){
                    sp++;
                    tp++;
                }else tp++;
            }
        }
        
        if(sp == s.end())
            return true;
        else return false;
    }
};