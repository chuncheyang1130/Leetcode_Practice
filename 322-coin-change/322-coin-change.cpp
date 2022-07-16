class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i >= coins[j] && dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(1+dp[i-coins[j]], dp[i]);
            }
        }
        if(dp[amount] == INT_MAX)
            return -1;
        else return dp[amount];
    }
};