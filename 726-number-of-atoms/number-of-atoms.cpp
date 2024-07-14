class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> count;
        int cur_const = 0;
        int base = 1;
        int total_const = 1;
        string cur_atom = "";
        stack<int> constant;

        for (int i = formula.size()-1; i >= 0; i--){
            if (formula[i] >= '0' && formula[i] <= '9'){
                cur_const += (formula[i]-'0') * base;
                base *= 10;
            }else if (formula[i] == ')'){
                if (cur_const == 0)
                    cur_const = 1;
                total_const *= cur_const;
                constant.push(cur_const);
                cur_const = 0;
                base = 1;
            }else if (formula[i] == '('){
                int pop_const = constant.top();
                constant.pop();
                total_const /= pop_const;
            }else if (formula[i] >= 'a' && formula[i] <= 'z'){
                cur_atom.insert(cur_atom.begin(), formula[i]);
            }else if (formula[i] >= 'A' && formula[i] <= 'Z'){
                cur_atom.insert(cur_atom.begin(), formula[i]);
                if (cur_const){
                    // cout << cur_atom << " " << cur_const * total_const << " " << count[cur_atom] << endl;;
                    // cout << cur_atom << " " << count[cur_atom] << " " << cur_const << " " << total_const << endl;
                    count[cur_atom] += cur_const * total_const;
                    cur_const = 0;
                }else{
                    // cout << cur_atom << " " << total_const << " " << count[cur_atom] << endl;;
                    count[cur_atom] += total_const;
                }
                cur_atom = "";
                cur_const = 0;
                base = 1;
            }
        }

        string ans = "";
        string val_str = "";
        int val;

        for (auto atom_cnt = count.begin(); atom_cnt != count.end(); atom_cnt++){
            ans.append(atom_cnt->first);
            val = atom_cnt->second;

            if (val == 1)
                continue;

            while (val){
                val_str.insert(val_str.begin(), '0' + val%10);
                val /= 10;
            }

            ans.append(val_str);
            val_str = "";
        }

        return ans;
    }
};