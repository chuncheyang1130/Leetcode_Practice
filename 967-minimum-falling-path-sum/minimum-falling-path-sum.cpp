class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int INF = 1e9;
        int n = matrix.size();

        for (int row = 1; row < n; row++){

            matrix[row][0] += min(matrix[row-1][0], matrix[row-1][1]);

            for (int col = 1; col < n-1; col++){
                matrix[row][col] += 
                        min({matrix[row-1][col-1], matrix[row-1][col+1], matrix[row-1][col]});
            }

            matrix[row][n-1] += min(matrix[row-1][n-1], matrix[row-1][n-2]);
        }
        
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};