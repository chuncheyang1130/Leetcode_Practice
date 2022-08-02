class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        vector<int> new_row;
        for(int i = 1; i <= rowIndex; i++){
            new_row.clear();
            new_row.resize(i+1);
            new_row[0] = 1;
            new_row[i] = 1;
            for(int j = 1; j < i; j++){
                new_row[j] = row[j-1] + row[j];
            }
            row = new_row;
        }
        return row;
    }
};