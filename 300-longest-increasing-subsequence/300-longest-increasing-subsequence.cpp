class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = {nums[0]};
        for(int i = 1; i < nums.size(); i++){
            auto it = lower_bound(dp.begin(), dp.end(), nums[i], less<int>());
            if(it == dp.end())
                dp.push_back(nums[i]);
            else if(*it > nums[i])
                dp[it-dp.begin()] = nums[i];
        }
        return dp.size();
    }
};