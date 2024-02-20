class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max_num = nums.size();
        int remain = 0;

        for (int i = 0; i < nums.size(); i++)
            remain += i - nums[i];

        return remain + max_num;
    }
};