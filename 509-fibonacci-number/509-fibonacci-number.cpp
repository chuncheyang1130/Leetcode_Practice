class Solution {
public:
    void multiply(vector<vector<int>> mat1, vector<vector<int>> mat2, vector<vector<int>>& res_mat){
        res_mat.clear();
        res_mat.resize(mat1.size(), vector<int>(mat2[0].size(), 0));
        for(int i = 0; i < mat1.size(); i++)
            for(int j = 0; j < mat2[0].size(); j++)
                for(int k = 0; k < mat1.size(); k++)
                    res_mat[i][j] += mat1[i][k] * mat2[k][j];  
                //res_mat[i][j] = mat1[i][0] * mat2[0][j] + mat1[i][1] * mat2[1][j];
    }
    int fib(int n) {
        
        if(n <= 1)
            return n;
        
        n -= 1;
        vector<vector<int>> unit = {{1, 1}, {1, 0}}, mat = {{1, 0}, {0, 1}}, value = {{1}, {0}};
        vector<vector<int>> res_mat;
        while(n > 0){
            if(n % 2){
                multiply(unit, mat, res_mat);
                mat = res_mat;
            }
            multiply(unit, unit, res_mat);
            unit = res_mat;
            n /= 2;
        }
        multiply(mat, value, res_mat);
        return res_mat[0][0];
    }
};