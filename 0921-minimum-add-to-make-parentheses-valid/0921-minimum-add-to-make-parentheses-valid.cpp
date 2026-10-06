class Solution {
public:
    int minAddToMakeValid(string s) {
        int n_move = 0, n_left = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == ')'){
                if (n_left == 0)
                    n_move += 1;
                else n_left -= 1;
            }else if (s[i] == '('){
                n_left += 1;
            }
        }

        
        return n_move + n_left;
    }
};