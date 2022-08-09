class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        unordered_map<char, vector<int>> table;
        vector<int> transfer;
        
        for(int i = text1.size()-1; i >= 0; i--)
            table[text1[i]].push_back(i);
        
        for(int i = 0; i < text2.size(); i++){
            for(int j = 0; j < table[text2[i]].size(); j++)
                transfer.push_back(table[text2[i]][j]);
        }
        
        if(transfer.size() == 0)
            return 0;
        vector<int> dp = {transfer[0]};
        
        for(int i = 1; i < transfer.size(); i++){
            auto it = lower_bound(dp.begin(), dp.end(), transfer[i], less<int>());
            if(it == dp.end())
                dp.push_back(transfer[i]);
            else if(*it > transfer[i])
                dp[it-dp.begin()] = transfer[i];
        }
        return dp.size();
    }
};