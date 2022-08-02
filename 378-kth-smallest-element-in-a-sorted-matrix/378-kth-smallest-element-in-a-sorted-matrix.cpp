class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 1)
             return matrix[0][0];
        
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        int ans;
        while(left <= right){
            int mid = (left+right)/2;
            cout << mid << " ";
            int cnt = 0;
            for(int i = 0; i < n; i++)
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            
            cout << cnt << endl;
            if(cnt >= k){
                right = mid - 1;
                ans = mid;
            }else left = mid + 1;
        }
        return ans;
        
    }
};