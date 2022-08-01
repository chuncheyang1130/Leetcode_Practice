class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0)
                    dp[j] = 1;
                else if(j != 0)
                    dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp.back();
    }
};