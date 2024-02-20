class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max_num = nums.size();
        int remain = (max_num + 1) * max_num / 2;

        for (int i = 0; i < nums.size(); i++)
            remain -= nums[i];

        return remain;
    }
};