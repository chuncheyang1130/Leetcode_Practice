class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;

        int k = 2;
        int prev_1 = nums[0], prev_2 = nums[1];
        for (int i = 2; i < nums.size(); i++){
            if (nums[i] != prev_1){
                nums[k] = nums[i];
                k += 1;
            }
            prev_1 = prev_2;
            prev_2 = nums[i];
        }

        return k;
    }
};