class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> w_table, p_table;
        vector<string> match;
        for(int i = 0; i < words.size(); i++){
            w_table.clear();
            p_table.clear();
            bool isPattern = true;
            for(int j = 0; j < words[i].size(); j++){
                if(w_table.find(words[i][j]) != w_table.end()){
                    if(pattern[j] != w_table[words[i][j]]){
                        isPattern = false;
                        break;
                    }
                }else if(p_table.find(pattern[j]) != p_table.end()){
                    isPattern = false;
                    break;
                }else{
                    w_table[words[i][j]] = pattern[j];
                    p_table[pattern[j]] = words[i][j];
                }
            }
            cout << endl;
            if(isPattern)
                match.push_back(words[i]);
        }
        return match;
    }
};