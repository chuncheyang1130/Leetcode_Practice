class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = target + 1e5;
        sort(nums.begin(), nums.end());
        int sum;
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int* l = &nums[i+1];
            int* r = &nums.back();
            while(l != r){
                sum = nums[i] + *l + *r;
                if(sum == target)
                    return sum;
                else if(abs(target-sum) < abs(target-closest))
                    closest = sum;
                 
                if(sum > target)
                    r--;
                else if(sum < target)
                    l++;
            }
            
        }
        return closest;
    }
};