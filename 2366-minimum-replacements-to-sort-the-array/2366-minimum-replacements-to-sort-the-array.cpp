class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        
        long long total = 0;
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] > nums[i+1]){
                int divide = ceil((double)nums[i] / nums[i+1]);
                total += divide - 1;
                nums[i] = nums[i] / divide;
            }
        }
        return total;
        
    }
};