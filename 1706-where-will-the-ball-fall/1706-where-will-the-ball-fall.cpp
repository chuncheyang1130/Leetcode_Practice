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
                if(i == 15 || i == 31){
                    cout << "down: " << down << endl;
                    cout << "left: " << left << endl;
                    cout << "up: " << up << endl;
                    cout << "row: " << row << endl;
                    cout << "col: " << col << endl;
                }
                if(down){
                    down = false;
                    if(grid[row][col] == 1){
                        left = false;
                        col++;
                    }else{
                        left = true;
                        col--;
                    }
                }else if(up){
                    break;
                }else{
                    if(left){
                        if(grid[row][col] == 1){
                            row--;
                            up = true;
                        }else{
                            row++;
                            down = true;
                        }
                    }else{
                        if(grid[row][col] == 1){
                            row++;
                            down = true;
                        }else{
                            row--;
                            up = true;
                        }
                    }
                }
                if(row == depth){
                    out = true;
                    break;
                }
            }
            
            if(out)
                ans[i] = col;
            else ans[i] = -1;
            
            if(i == 16 || i == 32){
                cout << "out: " << out << endl;
                cout << "ans: " << ans[i] << endl;
            }
        }
        return ans;
    }
};