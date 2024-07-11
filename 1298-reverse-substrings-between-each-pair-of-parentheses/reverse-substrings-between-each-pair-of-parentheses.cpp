class Solution {
public:
    string reverseParentheses(string s) {
        string str = "";
        stack<int> stk;
        int space = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] != '(' && s[i] != ')'){
                str.push_back(s[i]);
            }else{
                if (s[i] == '('){
                    stk.push(i-space);
                }else{
                    reverse(str.begin()+stk.top(), str.end());
                    stk.pop();
                }
                space++;
            }
        }
        
        return str;
    }
};