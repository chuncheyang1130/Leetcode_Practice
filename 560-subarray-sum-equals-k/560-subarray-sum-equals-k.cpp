class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        vector<int> sum(nums.size()+1);
        sum[0] = 0;
        int total = 0;
        
        for(int i = 0; i < nums.size(); i++)
            sum[i+1] = sum[i] + nums[i];
        
        for(int i = 0; i < sum.size(); i++){
            if(table.find(sum[i]-k) != table.end()){
                total += table[sum[i]-k];
            }
            table[sum[i]]++;
        }
        return total;
    }
};