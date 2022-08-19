class Solution {
public:
    void permute(vector<string>& ans, string& cur, int n, int left, int right){
        if(left == n && right == n){
            ans.push_back(cur);
            return;
        }
        
        if(left < n){
            cur[left+right] = '(';
            permute(ans, cur, n, left+1, right);
        }
        
        if(right < left){
            cur[left+right] = ')';
            permute(ans, cur, n, left, right+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur(n*2, ' ');
        permute(ans, cur, n, 0, 0);
        return ans;
    }
};