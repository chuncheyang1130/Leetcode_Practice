class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> row = {1};
        pascal.push_back(row);
        for(int i = 1; i < numRows; i++){
            row.clear();
            row.resize(i+1);
            row[0] = 1;
            row[i] = 1;
            for(int j = 1; j < i; j++){
                row[j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
            pascal.push_back(row);
        }
        return pascal;
    }
};