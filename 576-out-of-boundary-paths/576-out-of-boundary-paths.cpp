class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int M = 1e9 + 7;
        
        vector<vector<int>> dp(m, vector<int>(n, 0)), tmp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;
        int count = 0;
        
        for(int i = 0; i < maxMove; i++){
            for(int row = 0; row < m; row++){
                for(int col = 0; col < n; col++){
                    if(dp[row][col]){
                        if(row+1 == m) count = (count + dp[row][col]) % M;
                        else tmp[row+1][col] = (tmp[row+1][col] + dp[row][col]) % M;
                        
                        if(row == 0) count = (count + dp[row][col]) % M;
                        else tmp[row-1][col] = (tmp[row-1][col] + dp[row][col]) % M;
                        
                        if(col+1 == n) count = (count + dp[row][col]) % M;
                        else tmp[row][col+1] = (tmp[row][col+1] + dp[row][col]) % M;
                        
                        if(col == 0) count = (count + dp[row][col]) % M;
                        else tmp[row][col-1] = (tmp[row][col-1] + dp[row][col]) % M; 
                    }
                }
            }
            dp = tmp;
            tmp.clear();
            tmp.resize(m, vector<int>(n, 0));
        }
        return count;
    }
};