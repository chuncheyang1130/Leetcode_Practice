class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int local_max = nums[0], local_min = nums[0];
        int M = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0)
                swap(local_max, local_min);
            local_max = max(nums[i], nums[i]*local_max);
            local_min = min(nums[i], nums[i]*local_min);
            
            M = max(local_max, M);
        }
        return M;
        
    }
};