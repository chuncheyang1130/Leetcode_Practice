class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        sum.resize(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(j == 0)
                    sum[i][j] = matrix[i][j];
                else sum[i][j] = sum[i][j-1] + matrix[i][j];
            }
        }
        
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                sum[i][j] += sum[i-1][j];

    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0)
            return sum[row2][col2];
        else if(row1 == 0)
            return sum[row2][col2] - sum[row2][col1-1];
        else if(col1 == 0)
            return sum[row2][col2] - sum[row1-1][col2];
        else return sum[row2][col2] - sum[row2][col1-1] - sum[row1-1][col2] + sum[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */