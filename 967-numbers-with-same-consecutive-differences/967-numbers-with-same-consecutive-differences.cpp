class Solution {
public:
    void permute(int pos, vector<int>& ans, string& number, int k){
        if(pos == number.size()){
            int value = stoi(number);
            ans.push_back(value);
            return;
        }
        
        if(number[pos-1]+k <= '9'){
            number[pos] = number[pos-1]+k;
            permute(pos+1, ans, number, k);
        }
        
        if(k != 0 && number[pos-1]-k >= '0'){
            number[pos] = number[pos-1]-k;
            permute(pos+1, ans, number, k);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        string str(n, ' ');
        vector<int> ans;
        
        for(int i = 1; i <= 9; i++){
            str[0] = '0' + i;
            permute(1, ans, str, k);
        }
        return ans;
    }
};