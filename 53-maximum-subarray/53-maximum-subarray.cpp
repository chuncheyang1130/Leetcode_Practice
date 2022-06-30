class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int cur_min = 0, cur_max = nums[0];
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            cur_max = max(sum-cur_min, cur_max);
            cur_min = min(cur_min, sum);
        }
        return cur_max;
    }
};