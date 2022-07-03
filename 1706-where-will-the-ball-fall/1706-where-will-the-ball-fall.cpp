class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int width = grid[0].size();
        int depth = grid.size();
        vector<int> ans(width);
        bool left, down, up, out;
        
        for(int i = 0; i < width; i++){
            down = true;
            up = false;
            left = false;
            int row = 0, col = i;
            out = false;
            while(row >= 0 && col < width && col >= 0){
                if(up || (!down && left && grid[row][col] == 1) || (!down && !left && grid[row][col] == -1)){
                    break;
                }else if(down){
                    down = false;
                    if(grid[row][col] == 1){
                        left = false;
                        col++;
                    }else{
                        left = true;
                        col--;
                    }
                }else if(left){
                    row++;
                    down = true;
                    
                }else{
                    row++;
                    down = true;
                }
                if(row == depth){
                    out = true;
                    break;
                }
            }
            
            if(out)
                ans[i] = col;
            else ans[i] = -1;
        
        }
        return ans;
    }
};