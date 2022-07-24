class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n-1;
        
        while(true){
            if(target == matrix[x][y])
                return true;
            if(target > matrix[x][y])
                x++;
            else y--;
            if(x == m || y == -1)
                break;
        }
        return false;
    }
};