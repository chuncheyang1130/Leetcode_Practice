class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        if (nums.size() <= 4)
            return 0;

        sort(nums.begin(), nums.end());

        int window_size = nums.size() - 3;
        int diff = INT_MAX;
        int temp = 0;

        for (int i = 0; i + window_size <= nums.size(); i++){
            temp = nums[i+window_size-1] - nums[i];
            
            if (temp < diff)
                diff = temp;
        }

        return diff;
    }
};