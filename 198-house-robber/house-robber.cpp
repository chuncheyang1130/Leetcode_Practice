class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 1)
            return nums[0];

        nums[1] = max(nums[1], nums[0]);

        for (int i = 2; i < nums.size(); i++){
            nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
        }

        return nums.back();
    }
};