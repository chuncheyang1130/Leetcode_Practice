class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string rev_str = str;

        reverse(rev_str.begin(), rev_str.end());

        return str == rev_str;
    }
};