class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int len = 1, max_l = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]+1)
                len++;
            else if(nums[i] > nums[i-1]+1){
                max_l = max(max_l, len);
                len = 1;
            }
        }
        max_l = max(max_l, len);
        return max_l;
    }
};