class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        vector<int> sol(2);
        for(int i = 0; i < nums.size(); i++){
            if(table.find(target-nums[i]) != table.end()){
                sol[0] = table[target-nums[i]];
                sol[1] = i;
                break;
            }else{
                table[nums[i]] = i;
            }
        }
        return sol;
    }
};