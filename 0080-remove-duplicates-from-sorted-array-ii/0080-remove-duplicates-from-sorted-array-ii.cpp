class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();

        int k = 2;

        for (int i = 2; i < nums.size(); i++){
            if (nums[i] != nums[k-2]){
                nums[k] = nums[i];
                k += 1;
            }
        }

        return k;
    }
};