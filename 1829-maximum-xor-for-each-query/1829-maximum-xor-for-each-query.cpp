class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int len = nums.size();
        vector<int> bit_count(maximumBit, 0);

        for (int i = 0; i < len; i++){
            for (int b = 0; b < maximumBit; b++){
                if (nums[i] & (1 << b))
                    bit_count[b]++;
            }
        }
        
        vector<int> ans(len, 0);

        for (int i = len-1; i >= 0; i--){
            int val = 0;
            for (int b = 0; b < maximumBit; b++){
                if (bit_count[b] % 2 == 0)
                    val += (1 << b);
            }

            for (int b = 0; b < maximumBit; b++){
                if (nums[i] & (1 << b))
                    bit_count[b]--;
            }

            ans[len-1-i] = val;
        }

        return ans;
    }
};