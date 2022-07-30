class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        unordered_map<char, int> t1, t2, tmp;
        
        for(int i = 0; i < words2.size(); i++){
            tmp.clear();
            for(int j = 0; j < words2[i].size(); j++)
                tmp[words2[i][j]]++;
            for(auto it = tmp.begin(); it != tmp.end(); it++){
                if(t2.find(it->first) == t2.end())
                    t2[it->first] = it->second;
                else t2[it->first] = max(it->second, t2[it->first]);
            }
        }
        
        for(int i = 0; i < words1.size(); i++){
            t1.clear();
            bool match = true;
            for(int j = 0; j < words1[i].size(); j++)
                t1[words1[i][j]]++;
            for(auto it = t2.begin(); it != t2.end(); it++){
                if(t1.find(it->first) != t1.end() && t1[it->first] >= it->second)
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