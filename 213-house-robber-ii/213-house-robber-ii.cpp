class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 3)
            return *max_element(nums.begin(), nums.end());
        
        vector<int> sum(nums.size());
        int M = 0;
        
        // case 1 -- house 0 and last house is not robbed
        sum[1] = nums[1];
        sum[2] = max(nums[1], nums[2]);
        for(int i = 3; i < nums.size()-1; i++)
            sum[i] = max(sum[i-1], sum[i-2]+nums[i]);
        
        M = max(M, sum[nums.size()-2]);
        
        // case 2 -- house 0 is robbed
        sum.clear();
        sum[2] = nums[2];
        sum[3] = max(nums[3], nums[2]);
        for(int i = 4; i < nums.size()-1; i++)
            sum[i] = max(sum[i-1], sum[i-2]+nums[i]);
        
        M = max(M, sum[nums.size()-2]+nums[0]);
        
        // case 3 -- last house is robbed
        sum.clear();
        sum[1] = nums[1];
        sum[2] = max(nums[2], nums[1]);
        for(int i = 3; i < nums.size()-2; i++)
            sum[i] = max(sum[i-1], sum[i-2]+nums[i]);
            
        M = max(M, sum[nums.size()-3]+nums.back());
        
        return M;
    }
};