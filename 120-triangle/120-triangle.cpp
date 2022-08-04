class Solution {
public:
    int minimumSub(vector<vector<int>>& triangle, vector<vector<int>>& dp, int row, int pos){
        if(row == triangle.size()-1)
            return triangle[row][pos];
        if(dp[row][pos] != INT_MAX)
            return dp[row][pos];
        
        int m = min(minimumSub(triangle, dp, row+1, pos), minimumSub(triangle, dp, row+1, pos+1));
        dp[row][pos] = m + triangle[row][pos];
        return dp[row][pos];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < dp[i].size(); j++)
                dp[i][j] = INT_MAX;
        }
        return minimumSub(triangle, dp, 0, 0);
    }
};