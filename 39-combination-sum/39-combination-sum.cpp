class Solution {
public:
    void combination(vector<int>& candidates, vector<vector<int>>& comb, int target, int ind, vector<int> cur){
        cur.push_back(candidates[ind]);
        target -= candidates[ind];
        
        if(target == 0){
            comb.push_back(cur);
            return;
        }
        
        for(int i = ind; i < candidates.size(); i++){
            if(target >= candidates[i])
                combination(candidates, comb, target, i, cur);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<vector<int>> comb;
        for(int i = 0; i < candidates.size(); i++)
            combination(candidates, comb, target, i, vector<int>());
        return comb;
    }
};