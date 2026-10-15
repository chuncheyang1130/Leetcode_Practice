class Solution {
public:
    int sumCounts(vector<int>& nums) {
        bitset<101> record;
        int count = 0;
        for (int l = 0; l < nums.size(); l++){
            record.reset();
            int tmp_count = 0;
            for (int r = l; r < nums.size(); r++){
                if (record[nums[r]] == 0)
                    tmp_count += 1;
                record[nums[r]] = 1;
                count += tmp_count * tmp_count;
            }
        }

        return count;
    }
};