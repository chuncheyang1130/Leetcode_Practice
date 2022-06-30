class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > triplets;
        vector<int> ans(3);
        if(nums.size() < 3)
            return triplets;
        for(int i = 0; i < nums.size()-2; i++){
            if(!triplets.empty() && triplets.back()[0] == nums[i])
                continue;
            int* l = &nums[i+1];
            int* r = &nums.back();
            while(l != r){
                if(*l + *r == -nums[i]){
                    if(!triplets.empty() && triplets.back()[0] == nums[i] && triplets.back()[1] == *l){
                        l++;
                        continue;
                    }
                    ans[0] = nums[i];
                    ans[1] = *l;
                    ans[2] = *r;
                    triplets.push_back(ans);
                    l++;
                }else if(*l + *r > -nums[i]){
                    r--;
                }else if(*l + *r < -nums[i]){
                    l++;
                }
            }
        }
        
        return triplets;
    }
};