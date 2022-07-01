class Solution {
public:
    int rob(vector<int>& nums) {
        int prev_rob_max = 0, cur_rob_max = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            swap(prev_rob_max, cur_rob_max);
            cur_rob_max = max(cur_rob_max+nums[i], prev_rob_max);    
        }
        return cur_rob_max;
        
    }
};