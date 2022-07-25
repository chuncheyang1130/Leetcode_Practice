class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        vector<int> range = {-1, -1};
        if(left != right){
            range[0] = left - nums.begin();
            range[1] = right - nums.begin()-1;
        }
        return range;
    }
};