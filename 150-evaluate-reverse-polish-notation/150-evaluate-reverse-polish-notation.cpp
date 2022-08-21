class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> op;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "/" && tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*"){
                int value = stoi(tokens[i]);
                op.push(value);
            }else{
                int n2 = op.top();
                op.pop();
                int n1 = op.top();
                op.pop();
                int value;
                if(tokens[i] == "+"){
                    value = n1 + n2;
                    op.push(value);
                }else if(tokens[i] == "-"){
                    value = n1 - n2;
                    op.push(value);
                }else if(tokens[i] == "*"){
                    value = n1 * n2;
                    op.push(value);
                }else if(tokens[i] == "/"){
                    value = n1 / n2;
                    op.push(value);
                }
            }
        }
        return op.top();
    }
};