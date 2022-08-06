class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> row_sum(mat.size(), vector<int>(mat[0].size()+1, 0));
        vector<vector<int>> block_sum(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i = 0; i < mat.size(); i++){
            for(int j = 1; j <= mat[i].size(); j++){
                row_sum[i][j] = row_sum[i][j-1] + mat[i][j-1];
            }
        }
        
        int l, r, u, d;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                l = (j-k>=0)?j-k:0;
                r = (j+k<=mat[i].size()-1)?j+k+1:mat[i].size();
                d = (i-k>=0)?i-k:0;
                u = (i+k<=mat.size()-1)?i+k:mat.size()-1;
                for(int m = d; m <= u; m++)
                    block_sum[i][j] += row_sum[m][r] - row_sum[m][l];
                
            }
        }
        return block_sum;
    }
};