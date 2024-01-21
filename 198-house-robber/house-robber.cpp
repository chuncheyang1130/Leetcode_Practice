class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int> dp(nums.size()+1, 0);
        dp[1] = nums[0];
        
        for (int i = 1; i < nums.size(); i++){
            dp[i+1] = max(dp[i], dp[i-1]+nums[i]);
        }

        return dp[nums.size()];
    }
};