class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        if (nums.size() <= 4)
            return 0;

        sort(nums.begin(), nums.end());

        int window_size = nums.size() - 3;
        int diff = INT_MAX;

        for (int i = 0; i + window_size <= nums.size(); i++){
            diff = min(diff, nums[i+window_size-1]-nums[i]);
        }

        return diff;
    }
};