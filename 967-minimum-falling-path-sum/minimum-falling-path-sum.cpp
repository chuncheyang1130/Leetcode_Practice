class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int INF = 1e9;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];

        for (int row = 1; row < n; row++){
            for (int col = 0; col < n; col++){
                int left = INF, right = INF, mid = INF;
                
                if (col > 0)
                    left = dp[row-1][col-1] + matrix[row][col];
                
                if (col < n-1)
                    right = dp[row-1][col+1] + matrix[row][col];
                
                mid = dp[row-1][col] + matrix[row][col];

                dp[row][col] = min({left, right, mid});
            }
        }
        
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};