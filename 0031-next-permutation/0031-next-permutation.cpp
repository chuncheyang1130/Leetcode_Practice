class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if (nums.size() == 1)
            return;

        int dec_point = -1;

        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] < nums[i+1]){
                dec_point = i;
            }
        }

        int min_n = 0;

        if (dec_point == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int swap_pos = dec_point+1;
        for (int i = dec_point+1; i < nums.size(); i++){
            if (nums[i] <= nums[swap_pos] && nums[i] > nums[dec_point])
                swap_pos = i;
        }

        int tmp = nums[dec_point];
        nums[dec_point] = nums[swap_pos];
        nums[swap_pos] = tmp;

        reverse(nums.begin()+dec_point+1, nums.end());
    }
};