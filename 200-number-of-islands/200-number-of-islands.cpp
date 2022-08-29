class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        int num = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(visit[i][j])
                    continue;
                else if(grid[i][j] == '0'){
                    visit[i][j] = true;
                    continue;
                }
                
                stack<pair<int, int>> st;
                st.push(pair<int,int>(i, j));
                while(!st.empty()){
                    pair<int, int> top = st.top();
                    st.pop();
                    if(visit[top.first][top.second])
                        continue;
                    
                    visit[top.first][top.second] = true;
                    if(top.first > 0 && !visit[top.first-1][top.second] && grid[top.first-1][top.second] == '1')
                        st.push(pair<int, int>(top.first-1, top.second));
                    if(top.first < grid.size()-1 && !visit[top.first+1][top.second] && grid[top.first+1][top.second] == '1')
                        st.push(pair<int, int>(top.first+1, top.second));
                    if(top.second > 0 && !visit[top.first][top.second-1] && grid[top.first][top.second-1] == '1')
                        st.push(pair<int, int>(top.first, top.second-1));
                    if(top.second < grid[0].size()-1 && !visit[top.first][top.second+1] && grid[top.first][top.second+1] == '1')
                        st.push(pair<int, int>(top.first, top.second+1));
                }
                num++;
            }
        }
        return num;
    }
};