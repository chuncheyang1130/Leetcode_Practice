class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs.front();
        for(int i = 1; i < strs.size(); i++){
            if(strs[i] == "")
                return "";
            int len = 0;
            for(int j = 0; j < strs[i].size(); j++){
                if(j == common.size())
                    break;
                else if(strs[i][j] != common[j]){
                    break;
                }else len++;
            }
            common = common.substr(0, len);
        }
        return common;
    }
};