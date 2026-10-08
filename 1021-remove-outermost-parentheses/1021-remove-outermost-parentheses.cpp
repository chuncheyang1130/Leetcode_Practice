class Solution {
public:
    string removeOuterParentheses(string s) {
        string new_str;
        vector<int> label(s.size());
        int n_layer = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                n_layer += 1;
                label[i] = n_layer;
            }else {
                label[i] = n_layer;
                n_layer -= 1;
            }
        }

        for (int i = 0; i < s.size(); i++){
            if (label[i] > 1)
                new_str.push_back(s[i]);
        }
        
        return new_str;
    }
};