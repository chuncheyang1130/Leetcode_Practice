class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max_num = nums.size();
        int temp = max_num + 1;
        int remain = (temp * max_num) >> 1;

        for (int i = 0; i < nums.size(); i++)
            remain -= nums[i];

        return remain;
    }
};