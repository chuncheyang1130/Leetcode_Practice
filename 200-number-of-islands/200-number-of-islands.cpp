class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        
        map<pair<int, int>, bool> land;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1'){
                    pair<int, int> p = pair<int,int>(i, j);
                    land[p] = false;
                }
        
        for(auto it = land.begin(); it != land.end(); it++){
            if(it->second)
                continue;
            
            stack<pair<int, int>> st;
            st.push(it->first);
            while(!st.empty()){
                pair<int,int> top = st.top();
                st.pop();
                if(land[top])
                    continue;
                
                land[top] = true;
                
                if(top.first > 0){
                    pair<int, int> p = pair<int, int>(top.first-1, top.second);
                    if(land.find(p) != land.end() && !land[p])
                        st.push(p);
                }
                if(top.first < grid.size()-1){
                    pair<int, int> p = pair<int, int>(top.first+1, top.second);
                    if(land.find(p) != land.end() && !land[p])
                        st.push(p);
                }
                if(top.second > 0){
                    pair<int, int> p = pair<int, int>(top.first, top.second-1);
                    if(land.find(p) != land.end() && !land[p])
                        st.push(p);
                }
                if(top.second < grid[0].size()-1){
                    pair<int, int> p = pair<int, int>(top.first, top.second+1);
                    if(land.find(p) != land.end() && !land[p])
                        st.push(p);
                }
            }
            num++;
        }
        return num;
    }
};