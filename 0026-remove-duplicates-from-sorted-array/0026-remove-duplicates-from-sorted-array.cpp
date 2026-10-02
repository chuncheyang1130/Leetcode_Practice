class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> tab;
        int k = 0;

        for (int i = 0; i < nums.size(); i++){
            if (tab.find(nums[i]) == tab.end()){
                tab[nums[i]] = 1;
                nums[k] = nums[i];
                k += 1;
            }
        }

        return k;
    }
};