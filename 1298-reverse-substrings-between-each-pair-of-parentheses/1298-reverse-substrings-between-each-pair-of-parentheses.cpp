class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> order;
        stack<int> stk;
        int space = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] != '(' && s[i] != ')'){
                order.push_back(i);
            }else{
                if (s[i] == '('){
                    stk.push(i-space);
                }else{
                    reverse(order.begin()+stk.top(), order.end());
                    stk.pop();
                }
                space++;
            }
        }

        string str = "";
        for (int i = 0; i < order.size(); i++)
            str.push_back(s[order[i]]);
        

        return str;
    }
};