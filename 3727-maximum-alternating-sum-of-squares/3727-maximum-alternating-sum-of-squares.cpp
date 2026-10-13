class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
            nums[i] = abs(nums[i]);

        sort(nums.begin(), nums.end(), greater<int>());

        int l_ptr = 0, r_ptr = nums.size()-1;
        while (l_ptr <= r_ptr){
            if (l_ptr == r_ptr){
                sum += (long long)nums[l_ptr] * (long long)nums[l_ptr];
            }
            else{
                sum += (long long)nums[l_ptr] * (long long)nums[l_ptr];
                sum -= (long long)nums[r_ptr] * (long long)nums[r_ptr];
            }
                
            l_ptr++; 
            r_ptr--;
        }

        return sum;
    }
};