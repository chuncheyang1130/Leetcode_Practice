class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n_zero = 0;
        long long int total = 1;
        vector<int> answer(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0)
                n_zero += 1;
            else total *= nums[i];
        }

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0 && n_zero == 1)
                answer[i] = (int)total;
            else if (nums[i] != 0 && n_zero == 0)
                answer[i] = total / nums[i];
        }

        return answer;
    }
};