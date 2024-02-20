class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max_num = nums.size();
        int temp = max_num + 1;
        int total = max_num * temp / 2;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        return total - sum;
    }
};