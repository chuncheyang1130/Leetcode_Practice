class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 1;
        string max_str = "";
        max_str += s[0];
        for(int i = 0; i < n; i++){
            int len = 1;
            int left = i, right = i;
            for(int j = 1; i-j >= 0 && i+j < n; j++){
                if(s[i-j] == s[i+j]){
                    left--;
                    right++;
                    len += 2;
                }else break;
            }
            if(max_len < right-left+1){
                max_str = s.substr(left, right-left+1);
                max_len = right-left+1;
            }
        }
        
        for(int i = 1; i < n; i++){
            int left = i-1, right = i;
            int len = 0;
            for(int j = 0; i+j < n && i-1-j >= 0; j++){
                if(s[left] == s[right]){
                    len += 2;
                    left--;
                    right++;
                }else break;
            }
            if(max_len < right-left-1){
                max_str = s.substr(left+1, right-left-1);
                max_len = right-left-1;
            }
        }
        return max_str;
    }
};