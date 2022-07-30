class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        vector<int> table(26, 0), tmp;
        
        for(int i = 0; i < words2.size(); i++){
            tmp.clear();
            tmp.resize(26, 0);
            for(int j = 0; j < words2[i].size(); j++)
                tmp[words2[i][j]-'a']++;
            for(int j = 0; j < 26; j++)
                table[j] = max(tmp[j], table[j]);
        }
        
        for(int i = 0; i < words1.size(); i++){
            tmp.clear();
            tmp.resize(26, 0);
            bool match = true;
            for(int j = 0; j < words1[i].size(); j++)
                tmp[words1[i][j]-'a']++;
            for(int j = 0; j < 26; j++){
                if(table[j] > tmp[j]){
                    match = false;
                    break;
                }
            }
            if(match)
                ans.push_back(words1[i]);
        }
        return ans;
    }
};