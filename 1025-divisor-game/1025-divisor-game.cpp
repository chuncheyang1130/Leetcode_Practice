class Solution {
public:
    bool divisorGame(int n) {
        if(n == 1)
            return false;
        
        vector<bool> win(n+1, false);
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= sqrt(i); j++){
                if(i % j == 0 && !win[i-j]){
                    win[i] = true;
                    break;
                }
            }
        }
        return win[n];
    }
};