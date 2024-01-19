class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int INF = 1e9;
        int n = matrix.size();

        for (int row = 1; row < n; row++){
            for (int col = 0; col < n; col++){
                int left = INF, right = INF, mid = INF;
                
                if (col > 0)
                    left = matrix[row-1][col-1];
                
                if (col < n-1)
                    right = matrix[row-1][col+1];
                
                mid = matrix[row-1][col];

                matrix[row][col] += min({left, right, mid});
            }
        }
        
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};