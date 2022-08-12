class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case '(':
                case '[':
                case '{':
                    par.push(s[i]);
                    break;
                case ')':
                    if(par.empty() || par.top() != '(')
                        return false;
                    else par.pop();
                    break;
                case ']':
                    if(par.empty() || par.top() != '[')
                        return false;
                    else par.pop();
                    break;
                case '}':
                    if(par.empty() || par.top() != '{')
                        return false;
                    else par.pop();
                    break;
            }
        }
        
        return par.empty();
    }
};