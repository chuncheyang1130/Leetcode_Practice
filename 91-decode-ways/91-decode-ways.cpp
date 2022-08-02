class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;
        else if(s.size() == 1)
            return s[0] != '0';
        
        vector<int> dp(s.size(), 0);
        if(s[s.size()-1] != '0')
            dp[s.size()-1]++;
        if(s[s.size()-2] != '0')
            dp[s.size()-2] += dp[s.size()-1];
        if(s[s.size()-2] == '1' || (s[s.size()-2] == '2' && s[s.size()-1] < '7'))
            dp[s.size()-2]++;
        
        for(int i = s.size()-3; i >= 0; i--){
            if(s[i] != '0')
                dp[i] += dp[i+1];
            if(s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};