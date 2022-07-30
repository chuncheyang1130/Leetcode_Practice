class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        unordered_map<char, int> table, tmp;
        
        for(int i = 0; i < words2.size(); i++){
            tmp.clear();
            for(int j = 0; j < words2[i].size(); j++)
                tmp[words2[i][j]]++;
            for(auto it = tmp.begin(); it != tmp.end(); it++){
                if(table.find(it->first) == table.end())
                    table[it->first] = it->second;
                else table[it->first] = max(it->second, table[it->first]);
            }
        }
        
        for(int i = 0; i < words1.size(); i++){
            tmp.clear();
            bool match = true;
            for(int j = 0; j < words1[i].size(); j++)
                tmp[words1[i][j]]++;
            for(auto it = table.begin(); it != table.end(); it++){
                if(tmp.find(it->first) != tmp.end() && tmp[it->first] >= it->second)
                    continue;
                else{
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