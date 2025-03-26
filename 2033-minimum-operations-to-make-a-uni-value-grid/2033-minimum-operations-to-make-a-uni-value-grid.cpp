class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vec;
        int reminder = -1;
        for (int m = 0; m < grid.size(); m++){
            for (int n = 0; n < grid[0].size(); n++){
                vec.push_back(grid[m][n]);
                if (reminder == -1)
                    reminder = grid[m][n] % x;
                else if (reminder != grid[m][n] % x)
                    return -1;
                
            }
        }
        sort(vec.begin(), vec.end(), greater<int>());
        int median = vec[vec.size()/2];
        int move = 0;

        for (int i = 0; i < vec.size(); i++)
            move += abs(vec[i] - median) / x;

        return move;
    }
};