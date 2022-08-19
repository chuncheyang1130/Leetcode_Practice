class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, tail;
        
        for(int i = 0; i < nums.size(); i++)
            cnt[nums[i]]++;
        
        for(int i = 0; i < nums.size(); i++){
            if(cnt[nums[i]] == 0)
                continue;
            
            cnt[nums[i]]--;
            
            if(tail[nums[i]-1]){
                tail[nums[i]-1]--;
                tail[nums[i]]++;
            }else if(cnt[nums[i]+1] && cnt[nums[i]+2]){
                cnt[nums[i]+1]--;
                cnt[nums[i]+2]--;
                tail[nums[i]+2]++;
            }else return false;
        }
        return true;
    }
};