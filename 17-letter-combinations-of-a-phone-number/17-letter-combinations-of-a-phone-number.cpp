class Solution {
public:
    void permute(vector<string>& ans, string& cur, int pos, string& digits){
        if(pos == digits.size()){
            ans.push_back(cur);
            return;
        }
        
        int num = digits[pos] - '2';
        int start = num*3;
        if(num == 6 || num == 7)
            start++;
        
        for(int i = start; i < start+3; i++){
            cur[pos] = 'a' + i;
            permute(ans, cur, pos+1, digits);
        }
        
        if(num == 7 || num == 5){
            cur[pos] = 'a' + start + 3;;
            permute(ans, cur, pos+1, digits);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>();
        vector<string> ans;
        string cur(digits.size(), ' ');
        permute(ans, cur, 0, digits);
        return ans;
    }
};