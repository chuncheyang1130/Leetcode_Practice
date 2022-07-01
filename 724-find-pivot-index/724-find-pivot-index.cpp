class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i-1];
        nums.push_back(nums.back());
        
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i-1] == nums.back()-nums[i])
                return i-1;
        }
        
        return -1;
    }
};