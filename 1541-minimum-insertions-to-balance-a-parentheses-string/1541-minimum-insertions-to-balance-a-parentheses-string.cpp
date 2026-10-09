class Solution {
public:
    int minInsertions(string s) {
        int n_insert = 0;
        int n_left = 0, n_right = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                if (n_right == 1){
                    n_insert += 1;
                    n_right = 0;
                }else{
                    n_left += 1;
                }
            }else {
                n_right += 1;
                if (n_left == 0){
                    n_insert += 1;
                    n_left += 1;
                }else {
                    if (n_right == 2){
                        n_left -= 1;
                        n_right = 0;
                    }
                }
            }
        }

        n_insert += 2 * n_left - n_right;
        return n_insert;
    }
};