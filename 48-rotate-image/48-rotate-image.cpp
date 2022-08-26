class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> tmp(n, vector<int>(n));
        
        for(int i = 0; i < n/2; i++){
            for(int j = i; j < n-i; j++){
                tmp[j][n-i-1] = matrix[i][j]; 
                tmp[n-i-1][n-j-1] = matrix[j][n-i-1];
                tmp[n-j-1][i] = matrix[n-i-1][n-j-1];
                tmp[i][j] = matrix[n-j-1][i];
            }
        }
        if(n % 2)
            tmp[n/2][n/2] = matrix[n/2][n/2];
        
        matrix = tmp;
    }
};