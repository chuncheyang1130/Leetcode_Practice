class Solution {
public:
    int combination(vector<int>& nums, vector<int>& dp, int target){
        if(dp[target] != -1)
            return dp[target];
        
        dp[target] = 0;
        for(int i = 0; i < nums.size(); i++){
            if(target >= nums[i])
                dp[target] += combination(nums, dp, target-nums[i]);
        }
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        dp[0] = 1;
        return combination(nums, dp, target);
    }
};