class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        if (nums.size() <= 4)
            return 0;

        sort(nums.begin(), nums.end());

        int diff = INT_MAX;
        int temp = 0;

        for (int i = 0; i + nums.size() - 3 <= nums.size(); i++){
            temp = nums[i+nums.size()-4] - nums[i];

            if (temp < diff)
                diff = temp;
        }

        return diff;
    }
};