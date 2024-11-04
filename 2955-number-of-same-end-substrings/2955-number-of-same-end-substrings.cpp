class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        vector<vector<int>> dp(26, vector<int>(s.size()+1, 0));
        for (int i = 0; i < s.size(); i++){
            int ch = s[i] - 'a';
            for (int j = 0; j < 26; j++){
                if (j == ch)
                    dp[j][i+1] = dp[j][i] + 1;
                else dp[j][i+1] = dp[j][i];
            }
        }

        vector<int> ans(queries.size(), 0);
        for (int q = 0; q < queries.size(); q++){
            int l = queries[q][0];
            int r = queries[q][1];
            
            for (int i = 0; i < 26; i++){
                int n_ch = dp[i][r+1] - dp[i][l];
                cout << (char)('a'+i) << ": " << n_ch << endl;
                if (n_ch >= 1){
                    ans[q] += n_ch * (n_ch+1) / 2;
                }
            }
            cout << endl;
        }

        return ans;
    }
};