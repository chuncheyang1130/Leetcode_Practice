class Solution {
public:
    
    bool canSortArray(vector<int>& nums) {
        if (nums.size() == 1)
            return true;

        int n_sb = 0;
        int cur_min = nums[0];
        int cur_max = nums[0];
        int prev_max = 0;

        for (int i = 0; i <= 8; i++)
            n_sb += (nums[0] & (1 << i)) >> i;  
        
        for (int i = 1; i < nums.size(); i++){
            int tmp = 0;
            for (int j = 0; j <= 8; j++)
                tmp += (nums[i] & (1 << j)) >> j; 

            if (tmp == n_sb){
                cur_min = min(cur_min, nums[i]);
                cur_max = max(cur_max, nums[i]);
            }else {
                if (cur_min < prev_max)
                    return false;
                n_sb = tmp;
                prev_max = cur_max;
                cur_min = nums[i];
                cur_max = nums[i];
            }
        }
        
        if (cur_min < prev_max)
            return false;

        return true;
    }
};