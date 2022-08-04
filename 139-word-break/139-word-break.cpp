class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < wordDict.size(); j++){
                if(i == wordDict[j].size())
                    dp[i-1] = dp[i-1] || (s.substr(0, i) == wordDict[j]);
            }
            for(int j = 0; j < wordDict.size(); j++){
                if(wordDict[j].size() <= s.size()-i && dp[i-1]){
                    dp[i+wordDict[j].size()-1] = dp[i+wordDict[j].size()-1] || s.substr(i, wordDict[j].size()) == wordDict[j];
                }
            }
        }
        return dp.back();
    }
};