class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;

        int max_product = INT_MIN;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] >= 0)
                positive.push_back(nums[i]);
            else negative.push_back(nums[i]);
        }

        sort(positive.begin(), positive.end(), greater<int>());
        sort(negative.begin(), negative.end(), greater<int>());

        if (positive.size() >= 3)
            max_product = max(max_product, positive[0] * positive[1] * positive[2]);

        if (positive.size() >= 1 && negative.size() >= 2)
            max_product = max(max_product, positive[0] 
                                * negative[negative.size()-1] * negative[negative.size()-2]);

        if (positive.size() == 2 && negative.size() == 1)
            max_product = max(max_product, positive[0] * positive[1] * negative[0]);

        if (positive.empty() && negative.size() >= 3)
            max_product = max(max_product, negative[0] * negative[1] * negative[2]);

        return max_product;
    }
};