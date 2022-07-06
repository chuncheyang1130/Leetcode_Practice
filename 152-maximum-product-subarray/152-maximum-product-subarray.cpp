class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        long long product = 1, cur_max = INT_MIN, cur_min_pos = 1, cur_min_neg = 1;
        bool zero = false;
        for(int i = 0; i < nums.size(); i++){
            product *= nums[i];
            cur_max = max({cur_max, product/cur_min_pos, product/cur_min_neg});
            if(product > 0)
                cur_min_pos = min(cur_min_pos, product);
            else if(product < 0 && cur_min_neg == 1){
                cur_min_neg = product;
            }else if(product < 0 && cur_min_neg != 1){
                cur_min_neg = max(cur_min_neg, product);
            }else{
                zero = true;
                cur_min_neg = 1;
                cur_min_pos = 1;
                product = 1;
            }
        }
        
        if(zero)
            cur_max = max((int)cur_max, 0);
        return (int)cur_max;
    }
};