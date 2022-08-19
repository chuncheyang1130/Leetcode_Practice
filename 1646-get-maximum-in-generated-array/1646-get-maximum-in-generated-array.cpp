class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1)
            return n;
        
        vector<int> dp((n+1)/2+1, 0);
        dp[0] = 0, dp[1] = 1;
        int M = INT_MIN;
        
        for(int i = 2; i <= n; i++){
            if(i % 2){
                int tmp = dp[i/2] + dp[i/2+1];
                if(i < dp.size())
                    dp[i] = tmp;
                M = max(M, tmp);
            }else{
                int tmp = dp[i/2];
                if(i < dp.size())
                    dp[i] = tmp;
                M = max(M, tmp);
            }
        }
        return M;
    }
};