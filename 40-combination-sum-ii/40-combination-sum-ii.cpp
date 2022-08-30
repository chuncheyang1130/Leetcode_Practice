class Solution {
public:
    void comb(vector<int>& cur, vector<int>& cand, vector<vector<int>>& ans, int target, int pos){
        if(target == 0){
            ans.push_back(cur);
            return;
        }else if(pos == cand.size())
            return;
        
        cur.push_back(0);
        for(int i = pos; i < cand.size(); i++){
            if(i > pos && cand[i] == cand[i-1])
                continue;
            
            if(target >= cand[i]){
                cur[cur.size()-1] = cand[i];
                comb(cur, cand, ans, target-cand[i], i+1);
            }
        }
        cur.erase(cur.end()-1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        comb(cur, candidates, ans, target, 0);
        return ans;
    }
};