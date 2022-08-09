class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        
        unordered_map<int, int> table;
        
        
        for(int i = 0; i < nums.size(); i++){
            vector<int> new_element;
            for(auto it = table.begin(); it != table.end(); it++)
                new_element.push_back(it->first+nums[i]);
            
            for(int i = 0; i < new_element.size(); i++)
                table[new_element[i]] = 1;
            
            table[nums[i]] = 1;
            total += nums[i];
        }
        
        if(total % 2)
            return false;
        else return table.find(total/2) != table.end();
    }
};