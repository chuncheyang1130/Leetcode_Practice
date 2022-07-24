class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n-1;
        
        while(x != m && y != -1){
            if(target == matrix[x][y])
                return true;
            if(target > matrix[x][y])
                x++;
            else y--;
        }
        return false;
    }
};