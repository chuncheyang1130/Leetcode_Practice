class Solution {
public:
    void combine(vector<vector<int>>& ans, vector<int>& cur, int pos, int len, int n){
        if(pos == len){
            ans.push_back(cur);
            return;
        }    
        
        for(int i = cur[pos-1]+1; i <= n; i++){
            cur[pos] = i;
            combine(ans, cur, pos+1, len, n);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur(k);
        vector<vector<int>> ans;
        
        for(int i = 1; i <= n; i++){
            cur[0] = i;
            combine(ans, cur, 1, k, n);
        }
        
        return ans;
    }
};