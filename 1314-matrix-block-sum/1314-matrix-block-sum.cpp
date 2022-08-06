class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> sum(mat.size()+1, vector<int>(mat[0].size()+1, 0));
        vector<vector<int>> block_sum(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i = 1; i <= mat.size(); i++)
            for(int j = 1; j <= mat[i-1].size(); j++)
                sum[i][j] = sum[i][j-1] + mat[i-1][j-1];
        
        for(int i = 2; i <= mat.size(); i++)
            for(int j = 1; j <= mat[i-1].size(); j++)
                sum[i][j] += sum[i-1][j];  
        
        int l, r, u, d;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                l = (j-k>=0)?j-k:0;
                r = (j+k<=mat[i].size()-1)?j+k+1:mat[i].size();
                d = (i-k>=0)?i-k:0;
                u = (i+k<=mat.size()-1)?i+k+1:mat.size();
                
                block_sum[i][j] = sum[u][r] - sum[u][l] - sum[d][r] + sum[d][l];
            }
        }
        return block_sum;
    }
};