class Solution {
public:
    bool isAbleToMake(string& target, unordered_map<string, bool>& items){
        auto it = items.find(target);
        if (it != items.end()){
            if (it->second)
                return true;
            else
                return false;
        }
            
        return false;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> items;
        vector<string> ans;

        for (int i = 0; i < supplies.size(); i++)
            items[supplies[i]] = true;

        for (int t = 0; t < recipes.size(); t++){
            for (int i = 0; i < recipes.size(); i++){
                bool ableToMake = true;
                for (int j = 0; j < ingredients[i].size(); j++)
                    ableToMake = ableToMake && isAbleToMake(ingredients[i][j], items);
                
                if (ableToMake && items.find(recipes[i]) == items.end()){
                    items[recipes[i]] = true;
                    ans.push_back(recipes[i]);
                }
            }
        }

        return ans;
        
    }
};