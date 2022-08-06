class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                int m = INT_MAX;
                if(j > 0)
                    m = min(matrix[i-1][j-1], m);
                if(j < matrix[i].size()-1)
                    m = min(matrix[i-1][j+1], m);
                m = min(matrix[i-1][j], m);
                matrix[i][j] += m;
            }
        }
        return *min_element(matrix[matrix.size()-1].begin(), matrix[matrix.size()-1].end());
    }
};