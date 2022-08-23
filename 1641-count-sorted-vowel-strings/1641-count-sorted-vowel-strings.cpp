class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> cnt(5, 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < 5; j++)
                cnt[j] += cnt[j-1];
        }
        
        return cnt.back();
    }
};