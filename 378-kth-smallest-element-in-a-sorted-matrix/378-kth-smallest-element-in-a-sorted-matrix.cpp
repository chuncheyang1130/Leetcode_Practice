class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 1)
            return matrix[0][0];
        
        int n = matrix.size();
        vector<int> cur(n), cur_ind(n, 0);
        
        for(int i = 0; i < n; i++)
            cur[i] = matrix[i][0];
        
        int ans;
        for(int i = 1; i <= k; i++){
            int m = INT_MAX;
            int ind = 0;
            for(int j = 0; j < n; j++){
                if(cur[j] < m){
                    m = cur[j];
                    ind = j;
                }
            }
            if(i == k)
                ans = m;
            else{
                cur_ind[ind]++;
                if(cur_ind[ind] == n)
                    cur[ind] = INT_MAX;
                else cur[ind] = matrix[ind][cur_ind[ind]];
            }
        }
        return ans;
    }
};