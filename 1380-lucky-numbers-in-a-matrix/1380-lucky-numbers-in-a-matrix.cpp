class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        int min_col = 0;

        for (int iter = 0; iter < m; iter++){
            for (int c = 0; c < n; c++){
                if (matrix[iter][c] < matrix[iter][min_col])
                    min_col = c;
            }

            int r = 0;
            for ( ; r < m; r++){
                if (matrix[r][min_col] > matrix[iter][min_col])
                    break;
            }

            if (r == m)
                ans.push_back(matrix[iter][min_col]);
        }

        return ans;
    }
};