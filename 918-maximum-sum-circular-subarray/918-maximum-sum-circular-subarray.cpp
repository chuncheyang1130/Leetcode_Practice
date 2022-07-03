class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int cur_min = 0, cur_max = nums[0], sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            cur_max = max(cur_max, sum-cur_min);
            cur_min = min(cur_min, sum);
        }
        
        int M = cur_max;
        if(nums.size() >= 3){
            sum = 0;
            cur_max = 0;
            cur_min = INT_MAX;
            for(int i = 1; i < nums.size()-1; i++){
                sum += nums[i];
                cur_min = min(cur_min, sum-cur_max);
                cur_max = max(cur_max, sum);
            }

            M = max(M, sum + nums.front() + nums.back() - cur_min);
        }
        return M;
    }
};