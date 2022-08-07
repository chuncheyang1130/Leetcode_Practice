class Solution {
public:
    int countVowelPermutation(int n) {
        vector<int> vowel(5, 1), tmp(5);
        for(int i = 2; i <= n; i++){
            tmp[0] = vowel[1];
            tmp[1] = (vowel[0] + vowel[2]) % (int)(1e9+7);
            tmp[2] = ( ( (vowel[0] + vowel[1])%(int)(1e9+7) + vowel[3])%(int)(1e9+7) + vowel[4]) % (int)(1e9+7);
            tmp[3] = (vowel[2] + vowel[4]) % (int)(1e9+7);
            tmp[4] = vowel[0];
            vowel = tmp;
        }
        
        int total = 0;
        for(int i = 0; i < 5; i++){
            total += vowel[i];
            total %= (int)(1e9+7);
        }
        return total;
    }
};