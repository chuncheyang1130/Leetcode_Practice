class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> sum(nums.size());
        sum[0] = nums[0];
        
        int m = 0, M = nums[0], total = 0;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            M = max(M, total-m);
            m = min(total, m);
            if(i > 0)
                sum[i] = max(sum[i-1], total);
        }
        
        int cir_max = M, rev_sum = 0;
        for(int i = nums.size()-1; i >= 1; i--){
            rev_sum += nums[i];
            cir_max = max(cir_max, rev_sum+sum[i-1]);
        }
        return cir_max;
    }
};