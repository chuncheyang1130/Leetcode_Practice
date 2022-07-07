class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size()+s2.size())
            return false;
        vector<bool> dp(s2.size()+1);
        dp[0] = true;
        for(int i = 0; i < s1.size()+1; i++){
            for(int j = 0; j < dp.size(); j++){
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0)
                    dp[j] = (s2[j-1] == s3[i+j-1]) && dp[j-1];
                else if(j == 0)
                    dp[j] = dp[j] && (s1[i-1] == s3[i+j-1]);
                else
                    dp[j] = ((dp[j-1] && s2[j-1] == s3[i+j-1]) || (dp[j] && s1[i-1] == s3[i+j-1])) ;
            }
        }
        return dp.back();
    }
};