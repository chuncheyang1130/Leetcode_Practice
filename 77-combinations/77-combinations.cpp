class Solution {
public:
    void combine(vector<vector<int>>& ans, vector<bool>& used, vector<int>& cur, int pos, int len){
        if(pos == len){
            ans.push_back(cur);
            return;
        }    
        
        for(int i = cur[pos-1]+1; i < used.size(); i++){
            if(!used[i]){
                cur[pos] = i;
                used[i] = true;
                combine(ans, used, cur, pos+1, len);
                used[i] = false; 
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<bool> used(n+1, false);
        vector<int> cur(k);
        vector<vector<int>> ans;
        
        for(int i = 1; i < used.size(); i++){
            cur[0] = i;
            combine(ans, used, cur, 1, k);
        }
        
        return ans;
    }
};