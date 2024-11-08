class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int len = nums.size();
        int maximum = 0;
        vector<int> ans(len, 0);

        for (int b = 0; b < maximumBit; b++)
            maximum += 1 << b;

        int val = 0;
        for (int i = 0; i < len; i++)
            val ^= nums[i];
        
        for (int i = len-1; i >= 0; i--){
            ans[len-1-i] = maximum ^ val;
            val ^= nums[i];
        }

        return ans;
    }
};