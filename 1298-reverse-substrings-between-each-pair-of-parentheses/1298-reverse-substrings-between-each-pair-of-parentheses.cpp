class Solution {
public:
    string reverseParentheses(string s) {
        string str = "";
        stack<int> stk;
        

        for (int i = 0; i < s.size(); i++){
            if (s[i] != '(' && s[i] != ')'){
                str.push_back(s[i]);
            }else{
                if (s[i] == '('){
                    stk.push(str.size());
                }else{
                    reverse(str.begin()+stk.top(), str.end());
                    stk.pop();
                }
            }
        }

        return str;
    }
};