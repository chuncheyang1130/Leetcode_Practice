class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>> mat1, vector<vector<int>> mat2){
        vector<vector<int>> res_mat(mat1.size(), vector<int>(mat2[0].size(), 0));
        for(int i = 0; i < mat1.size(); i++)
            for(int j = 0; j < mat2[0].size(); j++)
                for(int k = 0; k < mat1.size(); k++)
                    res_mat[i][j] += mat1[i][k] * mat2[k][j];  
                //res_mat[i][j] = mat1[i][0] * mat2[0][j] + mat1[i][1] * mat2[1][j];
        return res_mat;
    }
    int fib(int n) {
        
        if(n <= 1)
            return n;
        
        n -= 1;
        vector<vector<int>> unit = {{1, 1}, {1, 0}}, mat = {{1, 0}, {0, 1}}, value = {{1}, {0}};
        while(n > 0){
            if(n % 2)
                mat = multiply(unit, mat);
            unit = multiply(unit, unit);
            n /= 2;
        }
        value = multiply(mat, value);
        return value[0][0];
    }
};