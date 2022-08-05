class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0])
            return 0;
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for(int i = 0; i < obstacleGrid.size(); i++){
            for(int j = 0; j < obstacleGrid[0].size(); j++){
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                else if(!obstacleGrid[i][j]){
                    if(i == 0)
                        dp[i][j] = dp[i][j-1];
                    else if(j != 0)
                        dp[i][j] = dp[i][j-1] + dp[i-1][j];
                    else dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp.back().back();
    }
};