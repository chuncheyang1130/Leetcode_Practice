class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int half = nums.size() / 2;

        for (int i = 1; i < nums.size(); i++){
            if (count.find(nums[i]) == count.end()){
                count[nums[i]] = 1;
            }else{
                count[nums[i]] += 1;
            }

            if (count[nums[i]] > half)
                return nums[i];
        }

        return nums[0];
    }
};