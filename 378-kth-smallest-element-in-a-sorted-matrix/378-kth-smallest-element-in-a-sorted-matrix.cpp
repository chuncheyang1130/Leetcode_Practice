class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 1)
            return matrix[0][0];
        
        int n = matrix.size();
        vector<int> cur(n), cur_ind(n, 0);
        
        for(int i = 0; i < n; i++)
            cur[i] = matrix[i][0];
        
        
        int ans, ind, m;
        for(int i = 1; i <= k; i++){
            ind = min_element(cur.begin(), cur.end())-cur.begin();
            m = cur[ind];
            
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