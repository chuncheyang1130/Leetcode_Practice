class Solution {
public:
    string reverseWords(string s) {
        int start = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(s.begin()+start, s.begin()+i);
                start = i+1;
            }
        }

        if(start != s.size()){
            reverse(s.begin()+start, s.end());
        }

        return s;
    }
};