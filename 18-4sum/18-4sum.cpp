class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        vector<int> ans;
        int *l, *r;
        
        if(nums.size() < 4)
            return quadruplets;
        
        sort(nums.begin(), nums.end());
        int subTarget;
        for(int i = 0; i < nums.size()-3; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            subTarget = target - nums[i];
            for(int j = i+1; j < nums.size()-2; j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                l = &nums[j+1];
                r = &nums.back();
                while(l != r){
                    if((long long)subTarget == (long long)nums[j] + *l + *r){
                        if(ans.empty()){
                            ans.resize(4);
                        }else if(ans[0] == nums[i] && ans[1] == nums[j] && ans[2] == *l && ans[3] == *r){
                            l++;
                            continue;
                        }
                        
                        ans[0] = nums[i];
                        ans[1] = nums[j];
                        ans[2] = *l;
                        ans[3] = *r;
                        quadruplets.push_back(ans);
                        l++;
                    }else if((long long)subTarget > (long long)nums[j] + *l + *r){
                        l++;
                    }else if((long long)subTarget < (long long)nums[j] + *l + *r){
                        r--;
                    }
                }
            }
        }
        return quadruplets;
    }
};