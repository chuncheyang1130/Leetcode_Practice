class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime_vec;

        for (int n = 1000; n >= 2; n--){
            int sq_root = sqrt(n);

            bool isPrime = true;
            for (int div = 2; div <= sq_root; div++){
                if (n % div == 0){
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                prime_vec.push_back(n);
        }
        
        bool inc = true;
        
        for (int i = 0; i < nums.size(); i++){
            auto begin_it = lower_bound(prime_vec.begin(), prime_vec.end(), nums[i], greater<int>());

            int prev = 0;
            if (i > 0)
                prev = nums[i-1];

            for (auto it = begin_it; it != prime_vec.end(); it++){
                if (nums[i] - *it > prev){
                    nums[i] -= *it;
                    break;
                }
            }

            if (nums[i] <= prev){
                inc = false;
                break;
            }
        }

        return inc;
    }
};