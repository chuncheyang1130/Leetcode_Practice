class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int ,int>> discover;
        int noRotten = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2)
                    discover.push(pair<int,int>(i, j));
                else if(grid[i][j] == 1)
                    noRotten++;
            }
        }
        
        int time = 0;
        while(!discover.empty() && noRotten){
            time++;
            int n = discover.size();
            while(n--){
                pair<int, int> pos = discover.front();
                cout << pos.first << " " << pos.second << endl;
                discover.pop();
                if(pos.first > 0 && grid[pos.first-1][pos.second] == 1){
                    discover.push(pair<int, int>(pos.first-1, pos.second));
                    grid[pos.first-1][pos.second] = 2;
                    noRotten--;
                }
                if(pos.first < grid.size()-1 && grid[pos.first+1][pos.second] == 1){
                    discover.push(pair<int, int>(pos.first+1, pos.second));
                    grid[pos.first+1][pos.second] = 2;
                    noRotten--;
                }
                if(pos.second > 0 && grid[pos.first][pos.second-1] == 1){
                    discover.push(pair<int, int>(pos.first, pos.second-1));
                    grid[pos.first][pos.second-1] = 2;
                    noRotten--;
                }
                if(pos.second < grid[0].size()-1 && grid[pos.first][pos.second+1] == 1){
                    discover.push(pair<int, int>(pos.first, pos.second+1));
                    grid[pos.first][pos.second+1] = 2;
                    noRotten--;
                }
            }
        }
        if(noRotten)
            return -1;
        return time;
    }
};