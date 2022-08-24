class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> dp;
        while(n > 0){
            dp.push_back(n % 3);
            n /= 3;
        }
        
        for(int i = 0; i < dp.size(); i++)
            if(dp[i] > 1)
                return false;
        
        return true;
    }
};